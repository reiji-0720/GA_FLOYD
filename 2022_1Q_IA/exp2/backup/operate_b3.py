import subprocess #terminalコマンド操作様のライブラリ
import time    #sleepを使うため



'''
設定箇所：以下の配列部分の変更を行うことで自動的にfloyd.cppの実行を行う
num で　全体の繰り返し回数を設定

配列の[0]の部分とfloyd.cppのDEFINEの値を同じにしてから実行をかける

以下はあまり設定しない様に!!!
------------------------------------------------------
func1 = ["rankingSelect()","tournamentSelect()"]
func2 = ["crossover1","crossover2","crossoverU"]
func1ex = ["\"ランキング選択\"","\"トーナメント選択\""]
func2ex = ["\"1点交叉\"","\"2点交叉\"","\"一様交叉\""]
------------------------------------------------------

'''

gene_max = [10,100,500,1000] #繰り返したいgene_maxの値を入力
pop_size = [10,100,500,1000]
elite = [1]
tounament_size = [1,10]
mutate_prob = [0.01,0.1]
max_num = [16,32,64]
func1 = ["rankingSelect()","tournamentSelect()"]
func2 = ["crossover1","crossover2","crossoverU"]
func1ex = ["\"ランキング選択\"","\"トーナメント選択\""]
func2ex = ["\"1点交叉\"","\"2点交叉\"","\"一様交叉\""]
num = 3 #全体の繰り返し回数


#一度実行
subprocess.call(["g++","floyd.cpp"])
subprocess.run('./a.out')

for i in range (num):
	for i in range(len(gene_max)):
		file_name = "floyd.cpp"
		with open(file_name, encoding="UTF-8")as f:
			data_lines = f.read()

		if i == len(gene_max)-1:
			data_lines = data_lines.replace("GENERATION_MAX	" + str(gene_max[i]),"GENERATION_MAX	" + str(gene_max[i-len(gene_max)+1]))
		else:
			data_lines = data_lines.replace("GENERATION_MAX	" + str(gene_max[i]),"GENERATION_MAX	" + str(gene_max[i+1]))
		with open(file_name, mode = "w", encoding="UTF-8")as f:
			f.write(data_lines)
			for j in range(len(pop_size)):

				file_name = "floyd.cpp"
				with open(file_name, encoding="UTF-8")as f:
					data_lines = f.read()
				if j == len(pop_size)-1:
					data_lines = data_lines.replace("POP_SIZE	" + str(pop_size[j]),"POP_SIZE	" + str(pop_size[j-len(pop_size)+1]))
				else:
					data_lines = data_lines.replace("POP_SIZE	" + str(pop_size[j]),"POP_SIZE	" + str(pop_size[j+1]))
				with open(file_name, mode = "w", encoding="UTF-8")as f:
					f.write(data_lines)
				for k in range(len(elite)):
					file_name = "floyd.cpp"
					with open(file_name, encoding="UTF-8")as f:
						data_lines = f.read()
					if k == len(elite)-1:
						data_lines = data_lines.replace("ELITE	" + str(elite[k]),"ELITE	" + str(elite[k-len(elite)+1]))
					else:
						data_lines = data_lines.replace("ELITE	" + str(elite[k]),"ELITE	" + str(elite[k+1]))
					with open(file_name, mode = "w", encoding="UTF-8")as f:
						f.write(data_lines)

					for l in range(len(tounament_size)):
						file_name = "floyd.cpp"
						with open(file_name, encoding="UTF-8")as f:
							data_lines = f.read()
						if l == len(tounament_size)-1:
							data_lines = data_lines.replace("TOURNAMENT_SIZE	" + str(tounament_size[l]),"TOURNAMENT_SIZE	" + str(tounament_size[l-len(tounament_size)+1]))
						else:
							data_lines = data_lines.replace("TOURNAMENT_SIZE	" + str(tounament_size[l]),"TOURNAMENT_SIZE	" + str(tounament_size[l+1]))
						with open(file_name, mode = "w", encoding="UTF-8")as f:
							f.write(data_lines)

						for m in range(len(mutate_prob)):
							file_name = "floyd.cpp"
							with open(file_name, encoding="UTF-8")as f:
								data_lines = f.read()
							if m == len(mutate_prob)-1:
								data_lines = data_lines.replace("MUTATE_PROB	" + str(mutate_prob[m]),"MUTATE_PROB	" + str(mutate_prob[m-len(mutate_prob)+1]))
							else:
								data_lines = data_lines.replace("MUTATE_PROB	" + str(mutate_prob[m]),"MUTATE_PROB	" + str(mutate_prob[m+1]))
							with open(file_name, mode = "w", encoding="UTF-8")as f:
								f.write(data_lines)

							for n in range(len(max_num)):
								file_name = "floyd.cpp"
								with open(file_name, encoding="UTF-8")as f:
									data_lines = f.read()
								if n == len(max_num)-1:
									data_lines = data_lines.replace("MAX_NUM	" + str(max_num[n]),"MAX_NUM	" + str(max_num[n-len(max_num)+1]))
								else:
									data_lines = data_lines.replace("MAX_NUM	" + str(max_num[n]),"MAX_NUM	" + str(max_num[n+1]))
								with open(file_name, mode = "w", encoding="UTF-8")as f:
									f.write(data_lines)








								for o in range(len(func1)):
									file_name = "floyd.cpp"
									with open(file_name, encoding="UTF-8")as f:
										data_lines = f.read()
										#data_lines2 = f.read()
									if o == len(func1)-1:
										data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o-len(func1)+1]))
										# data_lines = data_lines.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o-1]))
									else:
										data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o+1]))
										# data_lines = data_lines.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o+1]))
									with open(file_name, mode = "w", encoding="UTF-8")as f:
										f.write(data_lines)

									file_name = "floyd.cpp"
									with open(file_name, encoding="UTF-8")as f:
										data_lines = f.read()
										#data_lines2 = f.read()
									if o == len(func1)-1:
										#data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o-1]))
										data_lines = data_lines.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o-len(func1ex)+1]))
									else:
										# data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o+1]))
										data_lines = data_lines.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o+1]))
									with open(file_name, mode = "w", encoding="UTF-8")as f:
										f.write(data_lines)



									for p in range(len(func2)):
										file_name = "floyd.cpp"
										with open(file_name, encoding="UTF-8")as f:
											data_lines = f.read()
											#data_lines2 = f.read()
										if p == len(func2)-1:
											data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p-len(func2)+1]))
											#data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p-1]))
										else:
											data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p+1]))
											#data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p+1]))
										with open(file_name, mode = "w", encoding="UTF-8")as f:
											f.write(data_lines)

										file_name = "floyd.cpp"
										with open(file_name, encoding="UTF-8")as f:
											data_lines = f.read()
											#data_lines2 = f.read()
										if p == len(func2)-1:
											# data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p-1]))
											data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p-len(func2ex)+1]))
										else:
											# data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p+1]))
											data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p+1]))
										with open(file_name, mode = "w", encoding="UTF-8")as f:
											f.write(data_lines)

										subprocess.call(["g++","floyd.cpp"])
										subprocess.run('./a.out')








	# subprocess.call(["g++", "floyd.cpp"])

# for i in range(1):
# 	time.sleep(0.1)
# 	subprocess.run('./a.out')
