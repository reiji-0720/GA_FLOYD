with open("./result_list1.csv","rt",encoding='UTF-8') as file:
    x=file.read()
    # y=file.read()
    # z=file.read()
with open("./result_list1.csv","wt",encoding='UTF-8') as file:
    # x=x.replace("1様交叉","一様交叉")
    x=x.replace("一点交叉","1点交叉")
    # x=x.replace("二点交叉","2点交叉")
    file.write(x)
    # file.write(y)
    # file.write(z)

