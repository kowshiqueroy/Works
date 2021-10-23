cfg = {}
firstF = {}
followF = {}

inputs = []
while True:
    inp = input()
    if inp == "END":
        break
    inputs.append(inp)

for ip in inputs:
	if ip[0] not in cfg:
		cfg[ip[0]] = [ip[5:]]
	else:
		cfg[ip[0]].append(ip[5:])


non_terms = cfg.keys()
for i in cfg:
	for j in cfg[i]:
		for k in j:
			if k in non_terms:
				pass
			else:
				firstF[k] = [k]

"""
Function which calculates the first set of 'a'
"""
def cal_first(a):
	if a in firstF:
		#If first set of a is lreay calculated then return it
		return firstF[a]
	firstF[a] = []
	for i in cfg[a]:
		#For each rule in cfg whose lhs is 'a'
		for j in range(0, len(i)):
			#loop on length of rhs of each rule
			if i[j] not in non_terms:
				#if the term in the rule is terminal symbol
				if(j == len(i)-1 and i[j]=='@'):
					#if the given symbol is epsilon(@) and it is at last position add it to first set
					firstF[a].append('@')
				else:
					#else add first set of the first symbol on rhs in first of a
					firstF[a].extend(firstF[i[j]])
				break
			else:
				#if symbol is non terminal
				firstF[a].extend(cal_first(i[j]))
				#then add first set of that symbol to 'a'
				if('@' not in firstF[i[j]]):
					#if first set of that symbol doesn't contain epsilon, then we're done
					break
				else:
					if(j != len(i) - 1):
						#else if it is not the last symbol in rhs then remove epsilon
						firstF[a].remove('@')
	return firstF[a]

"""
Calculate first symbol for each non terminal
"""
for i in non_terms:
	cal_first(i)

for i in firstF:
	firstF[i] = list(set(firstF[i]))

fd = {}
for i in non_terms:
	followF[i] = []
	fd[i] = []

starting_symbol = str(input("Start: "))
followF[starting_symbol] = ['$']


for i in cfg:
	for q in cfg[i]:
		for j in range(0, len(q)):
			# for each symbol in rhs of each rule
			if q[j] in non_terms:
				#if it is non terminal
				if(j == len(q) - 1):
					#add a dependency that follow of that symbol contains follow of i
					fd[q[j]].append(i)
				else:
					for k in range(j+1, len(q)):
						#for the symbols following the current symbol
						if (k == len(q) -1) and ('@' in firstF[q[k]]):
							fd[q[j]].append(i)
							#same as above condition

						followF[q[j]].extend(firstF[q[k]])
						# add first set of next symbol in follow set of current symbol
						if('@' in firstF[q[k]]):
							#reomve epsilon from follow set, if any, and repeat the next symbolin the rule
							followF[q[j]].remove('@')
						else:
							#if there is no epsilon then we're done with that rule
							break


# for all dependencies add follow sets of dependent symbols to follow set of depending symbols
while(1):
	flag = False
	for i in fd:
		for j in fd[i]:
			prev_follow = followF[i]
			followF[i].extend(followF[j])
			if(prev_follow != followF[i]):
				flag = True

	if(not flag):
		# if there is no change in follow sets then break the loop
		break

for i in followF:
	followF[i] = list(set(followF[i]))

print ("First set is:  ")
print (firstF)
print ("\nFollow set is:  ")
print (followF)