result = {}
tCount=0

lS=['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
lC=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
priority={'^':1, '*':2, '/':2, '+':3, '-':3}

stack=[]
output=[]
stack_for_Ev=[]

def stackPopingForParenthesis():
    lenOfStack = len(stack)
    for i in range(lenOfStack):
        if stack[-1] !=')':
            output.append(stack.pop())

        else:
            stack.pop()
            return

inString=input("Input: ")


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
        result['t' + str(tCount)]= v1 + i + v2
        stack_for_Ev.append('t' + str(tCount))
        tCount+=1


print("\nThe three Address code:")
ltv=''
for i,j in result.items():
    print(i,"=",j)
    ltv=i
print(final_assign,"=",ltv)