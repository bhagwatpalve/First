def cric_and_bad(group1,group2):
    cric_and_bad = []
    for i in group1:
        for j in group2:
            if i==j and i not in cric_and_bad:
                cric_and_bad.append(i)
    return cric_and_bad

def cric_or_bad(group1,group2):
    cric_or_bad=[]
    for i in group1:
        if i not in cric_or_bad:
            cric_or_bad.append(i)
    for j in group2:
        if j not in cric_or_bad:
            cric_or_bad.append(j)
    return cric_or_bad

def cric_or_bad_not_both(group1,group2):
    c_or_b = cric_or_bad(group1, group2)
    c_and_b = cric_and_bad(group1,group2)
    cric_or_bad_not_both = []
    for i in c_or_b:
        if i not in c_and_b:
            if i not in cric_or_bad_not_both:
                cric_or_bad_not_both.append(i)
    return cric_or_bad_not_both
def neither_cric_nor_bad(group1,group2,group3):
    neither_cric_nor_bad=[]
    c_or_b= cric_or_bad(group1,group2)
    for i in group3:
        if i not in c_or_b:
            neither_cric_nor_bad.append(i)
    no1=len(neither_cric_nor_bad)
    return no1
def cric_and_foot_not_bad(group1,group2,group3):
    cric_and_foot_not_bad=[]
    cric_and_foot=[]
    for i in group1:
        for j in group3:
            if i == j and i not in cric_and_foot:
                cric_and_foot.append(i)
    for i in cric_and_foot:
        if i not in group2:
            cric_and_foot_not_bad.append(i)
    no2=len(cric_and_foot_not_bad)
    return no2

cricket=["Rahul","Kapil","Sarang","Sachin","Nikhil"]
badminton=["Rahul","Sagar","Sarang","Abhi","Amol"]
football=["Rahul","Kapil","Sarang","Abhi","Varad"]
p=cric_and_bad(cricket,badminton)
q=cric_or_bad_not_both(cricket,badminton)
r=neither_cric_nor_bad(cricket,badminton,football)
s=cric_and_foot_not_bad(cricket, badminton, football)
print("List of Students who play both cricket and badminton :",p,"\n")
print("List of Students who play either cricket or badminton but not both :",q,"\n")
print("Number of Students who play neither cricket nor badminton :",r,"\n")
print("Number of Students who play  cricket and football but not badminton :",s,"\n")