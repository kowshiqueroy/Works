import re

start_sym = ""
productions = {}
first_table = {} 
follow_table = {}
table = {}
i = 0

file = 'Input.txt'
grammar = open(file, "r")


def Create_Productions(grammar):
    global start_sym
    for production in grammar:
        lhs, rhs = re.split("->", production)
        rhs = re.split("\||\n", rhs)
        productions[lhs] = set(rhs) - {''}
        if not start_sym:
            start_sym = lhs


def isNonterminal(sym):
    if sym.isupper():
        return True
    else:
        return False


def Cal_first(sym):
    if sym in first_table:
        return first_table[sym];
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
    if sym not in follow_table:
        follow_table[sym] = set()
    for nt in productions.keys():
        for rule in productions[nt]:
            pos = rule.find(sym)
            if pos != -1:
                if pos == (len(rule) - 1):
                    if nt != sym:
                        i += 1
                        follow_table[sym] = follow_table[sym].union(Cal_follow(nt))
                else:
                    first_next = set()
                    for next in rule[pos + 1:]:
                        fst_next = Cal_first(next)
                        first_next = first_next.union(fst_next - {'@'})
                        if '@' not in fst_next:
                            break
                    if '@' in fst_next:
                        if nt != sym:
                            follow_table[sym] = follow_table[sym].union(Cal_follow(nt))
                            follow_table[sym] = follow_table[sym].union(first_next) - {'@'}
                    else:
                        follow_table[sym] = follow_table[sym].union(first_next)
    return follow_table[sym]


def PrintDetails():
    print("!! First Sets !!")
    for nt in productions:
        print(nt + ":" + str(first_table[nt]))
    print("\n")
    print("!! Follow Sets !!")
    for nt in productions:
        print(nt + ":" + str(follow_table[nt]))
    print("\n")


Create_Productions(grammar)
for nt in productions: #A B C
    first_table[nt] = Cal_first(nt)
follow_table[start_sym] = set('$')
for nt in productions:
    follow_table[nt] = Cal_follow(nt)

PrintDetails()
