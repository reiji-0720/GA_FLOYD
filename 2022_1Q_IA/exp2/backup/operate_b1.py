import subprocess #terminalコマンド操作様のライブラリ
import time    #sleepを使うため



gene_max = [10,100,1000]
pop_size = [10,100,1000]
elite = [1,2,5]
tounament_size = [1,10,50]
mutate_prob = [0.01,0.05,0.1,0.5]
max_num = [32,64,128]
func1 = ["rankingselect()","tournamentSelect()"]
func2 = ["crossover1","crossover2","crossoverU"]
func1ex = ["ランキング選択","トーナメント選択"]
func2ex = ["1点交叉","2点交叉","一様交叉"]


subprocess.call(["g++","floyd.cpp"])
time.sleep(2)
for i in range(1):
	time.sleep(0.1)
	subprocess.run('./a.out')


for i in range(3):
	file_name = "floyd.cpp"
	with open(file_name, encoding="UTF-8")as f:
		data_lines = f.read()

	if i == 2:
		data_lines = data_lines.replace("GENERATION_MAX	" + str(gene_max[j]),"GENERATION_MAX	" + str(gene_max[j-2]))
	else:
		data_lines = data_lines.replace("GENERATION_MAX	" + str(gene_max[i]),"GENERATION_MAX	" + str(gene_max[i+1]))
	with open(file_name, mode = "w", encoding="UTF-8")as f:
		f.write(data_lines)
		for j in range(3):

			file_name = "floyd.cpp"
			with open(file_name, encoding="UTF-8")as f:
				data_lines = f.read()
			if j == 2:
				data_lines = data_lines.replace("POP_SIZE	" + str(pop_size[j]),"POP_SIZE	" + str(pop_size[j-2]))
			else:
				data_lines = data_lines.replace("POP_SIZE	" + str(pop_size[j]),"POP_SIZE	" + str(pop_size[j+1]))
			with open(file_name, mode = "w", encoding="UTF-8")as f:
				f.write(data_lines)
			for k in range(3):
				file_name = "floyd.cpp"
				with open(file_name, encoding="UTF-8")as f:
					data_lines = f.read()
				if k == 2:
					data_lines = data_lines.replace("ELITE	" + str(elite[k]),"ELITE	" + str(elite[k-2]))
				else:
					data_lines = data_lines.replace("ELITE	" + str(elite[k]),"ELITE	" + str(elite[k+1]))
				with open(file_name, mode = "w", encoding="UTF-8")as f:
					f.write(data_lines)

				for l in range(3):
					file_name = "floyd.cpp"
					with open(file_name, encoding="UTF-8")as f:
						data_lines = f.read()
					if l == 2:
						data_lines = data_lines.replace("TOURNAMENT_SIZE	" + str(tounament_size[l]),"TOURNAMENT_SIZE	" + str(tounament_size[l-2]))
					else:
						data_lines = data_lines.replace("TOURNAMENT_SIZE	" + str(tounament_size[l]),"TOURNAMENT_SIZE	" + str(tounament_size[l+1]))
					with open(file_name, mode = "w", encoding="UTF-8")as f:
						f.write(data_lines)

					for m in range(4):
						file_name = "floyd.cpp"
						with open(file_name, encoding="UTF-8")as f:
							data_lines = f.read()
						if m == 3:
							data_lines = data_lines.replace("MUTATE_PROB	" + str(mutate_prob[m]),"MUTATE_PROB	" + str(mutate_prob[m-3]))
						else:
							data_lines = data_lines.replace("MUTATE_PROB	" + str(mutate_prob[m]),"MUTATE_PROB	" + str(mutate_prob[m+1]))
						with open(file_name, mode = "w", encoding="UTF-8")as f:
							f.write(data_lines)

						for n in range(3):
							file_name = "floyd.cpp"
							with open(file_name, encoding="UTF-8")as f:
								data_lines = f.read()
							if n == 2:
								data_lines = data_lines.replace("MAX_NUM	" + str(max_num[n]),"MAX_NUM	" + str(max_num[n-2]))
							else:
								data_lines = data_lines.replace("MAX_NUM	" + str(max_num[n]),"MAX_NUM	" + str(max_num[n+1]))
							with open(file_name, mode = "w", encoding="UTF-8")as f:
								f.write(data_lines)

							for o in range(2):
								file_name = "floyd.cpp"
								with open(file_name, encoding="UTF-8")as f:
									data_lines = f.read()
									data_lines2 = f.read()
								if o == 1:
									data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o-1]))
									data_lines2 = data_lines2.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o-1]))
								else:
									data_lines = data_lines.replace("FUNCTION1	" + str(func1[o]),"FUNCTION1	" + str(func1[o+1]))
									data_lines = data_lines2.replace("FUNCTION1EXPORT	" + str(func1ex[o]),"FUNCTION1EXPORT	" + str(func1ex[o+1]))
								with open(file_name, mode = "w", encoding="UTF-8")as f:
									f.write(data_lines)

								for p in range(2):
									file_name = "floyd.cpp"
									with open(file_name, encoding="UTF-8")as f:
										data_lines = f.read()
										data_lines2 = f.read()
									if p == 1:
										data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p-1]))
										data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p-1]))
									else:
										data_lines = data_lines.replace("FUNCTION2	" + str(func2[p]),"FUNCTION2	" + str(func2[p+1]))
										data_lines = data_lines.replace("FUNCTION2EXPORT	" + str(func2ex[p]),"FUNCTION2EXPORT	" + str(func2ex[p+1]))
									with open(file_name, mode = "w", encoding="UTF-8")as f:
										f.write(data_lines)

									subprocess.call(["g++","floyd.cpp"])
									subprocess.run('./a.out')






	# subprocess.call(["g++", "floyd.cpp"])

# for i in range(1):
# 	time.sleep(0.1)
# 	subprocess.run('./a.out')
