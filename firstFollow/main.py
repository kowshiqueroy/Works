import re

file = 'inputfile.txt'
grammarInput = open(file, "r")


def Create_Productions(grammar):
    global startSymbol
    for production in grammar:
        lhs, rhs = re.split("->", production)
        rhs = re.split("\||\n", rhs)
        productions[lhs] = set(rhs) - {''}
        if not startSymbol:
            startSymbol = lhs


def isNonterminal(sym):
    if sym.isupper():
        return True
    else:
        return False


def Cal_first(sym):
    if sym in firstList:
        return firstList[sym];
    if isNonterminal(sym):
        first = set()
        for x in productions[sym]:
            if x == '@':
                first = first.union('@')
            else:
                for i in x:
                    fst = Cal_first(i)
                    if i != x[-1]:
                        first = first.union(fst - {'@'})
                    else:
                        first = first.union(fst)
                    if '@' not in fst:
                        break
        return first;
    else:
        return set(sym)


def Cal_follow(sym):
    global i
    if sym not in followList:
        followList[sym] = set()
    for nt in productions.keys():
        for rule in productions[nt]:
            pos = rule.find(sym)
            if pos != -1:
                if pos == (len(rule) - 1):
                    if nt != sym:
                        i += 1
                        followList[sym] = followList[sym].union(Cal_follow(nt))
                else:
                    first_next = set()
                    for next in rule[pos + 1:]:
                        fst_next = Cal_first(next)
                        first_next = first_next.union(fst_next - {'@'})
                        if '@' not in fst_next:
                            break
                    if '@' in fst_next:
                        if nt != sym:
                            followList[sym] = followList[sym].union(Cal_follow(nt))
                            followList[sym] = followList[sym].union(first_next) - {'@'}
                    else:
                        followList[sym] = followList[sym].union(first_next)
    return followList[sym]



startSymbol = ""
productions = {}
firstList = {}
followList = {}
table = {}
i = 0


Create_Productions(grammarInput)
for nt in productions:
    firstList[nt] = Cal_first(nt)

followList[startSymbol] = set('$')

for nt in productions:
    followList[nt] = Cal_follow(nt)



print("First Function")
for nt in productions:
    print(nt + ":" + str(firstList[nt]))
print("\n")
print("Follow Function")
for nt in productions:
    print(nt + ":" + str(followList[nt]))
print("\n")
