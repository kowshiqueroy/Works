
result = {}
tCounter=0

lS=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
lC=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
priority={'^':1, '*':2, '/':2, '+':3, '-':3}
all = lC + lS
stack=[]
output=[]
stack_for_Ev=[]

def unaryOp (uniString):
    #print(all)
    for s in all:
        if s == uniString[0]:
            if (uniString[1] == '+' and uniString[2] == '+') or (uniString[1] == '-' and uniString[2] == '-'):
                print("t0= "+ uniString[0]+ " "+uniString[1]+ " 1\n"+uniString[0]+" = t0")
                exit()
    for s in all:
        if s == uniString[2]:
            if (uniString[1] == '+' and uniString[0] == '+') or (uniString[1] == '-' and uniString[0] == '-'):
                print("t0= "+ uniString[2]+" "+uniString[1]+ " 1\n"+uniString[2]+" = t0")
                exit()
    for s in all:

        if s == uniString[0]  and uniString[1]=='=':
            for s in all:

                if s == uniString[4]:
                     if (uniString[3] == '+' and uniString[2] == '+') or (uniString[3] == '-' and uniString[2] == '-'):
                        print("t0= "+ uniString[4]+" "+uniString[3]+ " 1\n"+uniString[0]+" = t0")
                        exit()
                if s == uniString[2]:
                     if (uniString[3] == '+' and uniString[4] == '+') or (uniString[3] == '-' and uniString[4] == '-'):
                        print(uniString[0]+"="+uniString[2]+"\nt0= "+ uniString[2]+" "+uniString[3]+ " 1\n"+uniString[2]+" = t0")
                        exit()
                if uniString[2]== '-':
                    print("t0= " + uniString[4] + " " + uniString[5] + " "+ uniString[6]+ "\nt1= -t0\n"+ uniString[0] + " =t1")
                    exit()






def stackPopingForParenthesis(): 
    lenOfStack = len(stack)
    for i in range(lenOfStack):
        if stack[-1] !=')':
            output.append(stack.pop())

        else:  
            stack.pop()
            return

inString=input("Input: ")

unaryOp(inString)


final_assign = ""
equation = ""
remove_space = ''  
for i in inString:
    if i != " ":
        remove_space += i

final_assign, equation = remove_space.split("=")
equation=equation[::-1] 

for i in equation: 

    if (i in lC) or (i in lS) or (i > '0' and i < '9'):
        output.append(i)

    elif len(stack)==0 and (i=='^' or i=='*' or i=='/' or i=='-' or i=='+'): 
        stack.append(i)

    elif i==')': 
        stack.append(i)

    elif i=='(': 
        stackPopingForParenthesis() 

    elif i=='^' or i=='*' or i=='/' or i=='-' or i=='+': 

        if stack[-1]==')':
            stack.append(i)


        elif priority[i]<= priority[stack[-1]]:
            stack.append(i)


        else: 
            output.append(stack.pop())
            stack.append(i)




final_lenOfStack= len(stack)
if final_lenOfStack: 
    for i in range(final_lenOfStack):
        output.append(stack.pop())

preFix=output[::-1]
#print("prefix:", preFix)
prefix= output 

for i in prefix:
    if (i in lC) or (i in lS) or (i > '0' and i < '9'):
        stack_for_Ev.append(i) 
    elif (i=='^' or i=='*' or i=='/' or i=='-' or i=='+'): 
        v1=stack_for_Ev.pop()
        v2=stack_for_Ev.pop()
        result['t' + str(tCounter)]= v1 + i + v2
        stack_for_Ev.append('t' + str(tCounter))
        tCounter+=1



#print("\nThe three Address code:")
ltv=''
for i,j in result.items():
    print(i,"=",j)
    ltv=i
print(final_assign,"=",ltv)