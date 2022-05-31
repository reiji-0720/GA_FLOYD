import os,sys



def replace_func(fname, replace_set):
	target, replce = replace_set

	with open(fname,'r') as f1:
		tmp_list = []
		for row in f1:
			if row.find(target) != -1:
				tmp_list.append(replce)
			else:
				tmp_list.append(row)
	with open(fname,'w') as f2:
		for i in range(len(tmp_list)):
			f2.write(tmp_list[i])





if __name__ == '__main__': #このファイルを本体として実行した場合、mainが実行される。

	gene_max = [2000,100,500,1000] #繰り返したいgene_maxの値を入力
	pop_size = [3000,100,500,1000]
	elite = [2]
	tounament_size = [5,10]
	mutate_prob = [0.23,0.1]
	max_num = [425,32,64]
	func1 = ["test()","tournamentSelect()"]
	func2 = ["testing()","crossover2","crossoverU"]
	func1ex = ["\"ラン選択\"","\"トーナメント選択\""]
	func2ex = ["\"交叉\"","\"2点交叉\"","\"一様交叉\""]
	# param set
	fname = './test.txt'



	replace_setA = ('#define GENERATION_MAX',"#define GENERATION_MAX	"+str(gene_max[0])+"\n")
	replace_setB = ('#define POP_SIZE',"#define POP_SIZE	" + str(pop_size[0])+"\n")
	replace_setC = ('#define ELITE',"#define ELITE	" + str(elite[0])+"\n")
	replace_setD = ('#define TOURNAMENT_SIZE',"#define TOURNAMENT_SIZE	" + str(tounament_size[0])+"\n")
	replace_setE = ('#define MUTATE_PROB',"#define MUTATE_PROB	" + str(mutate_prob[0])+"\n")
	replace_setF = ('#define MAX_NUM',"#define MAX_NUM	" + str(max_num[0])+"\n")
	replace_setG = ('#define FUNCTION1',"#define FUNCTION1	" + str(func1[0])+"\n")
	replace_setH = ('#define FUNC1EXPORT',"#define FUNC1EXPORT	" + str(func1ex[0])+"\n")
	replace_setI = ('#define FUNCTION2',"#define FUNCTION2	" + str(func2[0])+"\n")
	replace_setJ = ('#define FUNC2EXPORT',"#define FUNC2EXPORT	" + str(func2ex[0])+"\n")

	# call func


	replace_func(fname , replace_setA)
	replace_func(fname , replace_setB)
	replace_func(fname , replace_setC)
	replace_func(fname , replace_setD)
	replace_func(fname , replace_setE)
	replace_func(fname , replace_setF)
	replace_func(fname , replace_setG)
	replace_func(fname , replace_setH)
	replace_func(fname , replace_setI)
	replace_func(fname , replace_setJ)

		#replace_func(fname , str_rep)
