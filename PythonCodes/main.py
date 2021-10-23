#Symbol Table with Hash chaining
#ht =>Hash table
# vl=> Value ty=>Type
ht = [[] for _ in range(10)] #Nested Listing 10X10
#10 value

#print (ht) #debuging


def hf(vl): #hash_Making_Func
	vl= ord(vl[0]) #vl = Value in ASCII NUM
	return vl % len(ht)  # value's ASCII % 10


def insert(ht, vl, ty): # ty Type
	hash_key = hf(vl)
	key_is_avail = False
	bucket = ht[hash_key]
	for i, vt in enumerate(bucket): # looping through the list
		v, t = vt
		if vl == v:
			key_is_avail = True
			break
	if key_is_avail:
		bucket.append((vl, ty))

	else:
		bucket.append((vl, ty))




def update(ht, vl, ty):
	hash_key = hf(vl)
	key_is_avail = False
	bucket = ht[hash_key]
	for i, vt in enumerate(bucket): # looping through the list
		v, t = vt
		if vl == v:
			key_is_avail = True
			break
	if key_is_avail:

		bucket[i]=(( vl, ty))
	else:
		bucket.append((vl, ty))



def search(ht, vl):
	hash_key = hf(vl)
	bucket = ht[hash_key]
	for i, vt in enumerate(bucket):
		v, t = vt
		if vl == v:
			return v , t



def delete(hash_table, vl):
	hash_key = hf(vl)
	key_exists = False
	bucket = hash_table[hash_key]
	for i, vt in enumerate(bucket):
		v, t = vt
		if vl == v:
			key_exists = True
			break
	if key_exists:
		del bucket[i]
		print ('value {} deleted'.format(vl))
	else:
		print ('Value {} not found'.format(vl))



def show(ht): #print function
	print(ht)




def mainf():
	print("Type 1 for insert/ 2 for show/ 3 for delete/ 4 for update/ 5 for serach/ 6 for hash value 0 for exit")
	c=int(input())

	if c == 1: #adding
		print("Insert value type")
		line= str(input())
		words=line.split(" ")
		print(words)
		insert(ht, words[0], words[1]) #only first 2 index will be counted
		mainf()
	elif c==2: #print
		print("Show all")
		show(ht)
		mainf()

	elif c==3: #delete
		print("delete value")
		delete(ht, str(input()))
		mainf()

	elif c==4: #update
		print("Update value type")
		line = str(input())
		words = line.split(" ")
		print(words)
		update(ht, words[0], words[1])
		mainf()

	elif c==5: #search
		print("Search value")
		print(search(ht, str(input())))
		mainf()

	elif c==6: #Hash Value
		print("Search Hash value")
		print(hf(str(input())))
		mainf()

	elif c==0: #exit
		exit()

	else: #other cases
		print("Invalid type")
		mainf()


mainf() #main function recuring call