//文字コードをSHIFT-JIS-->>UTF-8に変更しコンパイル成功

// floyd.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
// ヘッダファイルのインクルード
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>

// 定数の定義
#define GENERATION_MAX		1000	// 世代交代数
#define POP_SIZE		1000	// 個体集団内の個体の数
#define ELITE			1	// エリート保存戦略で残す個体の数
#define TOURNAMENT_SIZE		10	// トーナメント選択で無作為抽出する個体の数
#define MUTATE_PROB		0.01	// 突然変異確率
#define MAX_NUM			64	// フロイド問題におけるN

// 構造体の定義
typedef struct individual {
	double fitness;			// 適応度
	int chrom[MAX_NUM];		// 染色体
} Individual;

// グローバル変数の宣言
Individual population[POP_SIZE];	// 個体集団
Individual nextPop[POP_SIZE];		// 個体集団
float comptime;				// 処理時間
double dSumOfSquare;			// 平方根和の差

// 関数の宣言
void evaluation();
void newGeneration();
void printResult(Individual *best);
void sort(int lb, int ub);
int rankingSelect();
int tournamentSelect();
void crossover1(Individual *p1, Individual *p2, Individual *c1, Individual *c2);
void crossover2(Individual *p1, Individual *p2, Individual *c1, Individual *c2);
void crossoverU(Individual *p1, Individual *p2, Individual *c1, Individual *c2);
void mutate(Individual *c);
void culculate(Individual *best); //平方根和の差を計算

// メインルーチン
int main()
{
	int i, j, gen;
	clock_t start;

	// 時間計測スタート
	start = clock();

	// 乱数のタネの設定
	srand((unsigned int)time(NULL));

	// 初期集団生成
	// ****************************************************************************************
	for(i=0;i<POP_SIZE;i++){
		//printf("第%d世代の遺伝子は\n", i);
		for(j=0;j<MAX_NUM;j++){
			population[i].chrom[j] = rand()%2;	//i番目の個体のj番目の遺伝子に0or1を代入
			//printf("%d", population[i].chrom[j]);
		}
		population[i].fitness = 0.0; //　i番目の個体の適応度は0.0
		//printf("\n");

	}
	evaluation();
	// ****************************************************************************************
	// 進化
	for(gen = 1; gen <= GENERATION_MAX; gen++) {
		// 次世代生成
		newGeneration();
		// 評価
		evaluation();
		// 途中経過表示
		printf("第%d世代\t最良個体の適応度は%lf\n", gen, population[0].fitness);

	}
	culculate(&population[0]);
	// 処理時間計算
	comptime = (float)(clock() - start) / CLOCKS_PER_SEC;

	// 結果表示
	printResult(&population[0]);

	return 0;
}

// 評価
void evaluation()
{
	int i, j;

	// ****************************************************************************************
	for(i=0;i<POP_SIZE;i++){
		population[i].fitness=0.0;
		for(j=0;j<MAX_NUM;j++){
			population[i].fitness += (2*population[i].chrom[j]-1) * sqrt((double)j+1);
		}

		population[i].fitness = fabs(population[i].fitness);
	}
	sort(0,POP_SIZE-1);

	// ****************************************************************************************
}

// 次世代生成
void newGeneration()
{
	int i, j, a, b;

	// エリート保存戦略
	// ****************************************************************************************

	for(i=0;i<ELITE;i++){
		nextPop[i]=population[i];
	}


	// ****************************************************************************************

	// ランキング選択＆一点交叉
	// ****************************************************************************************

	for(i=ELITE;i<POP_SIZE-1;i+=2){
		a=rankingSelect();
		b=rankingSelect();
		//printf("a:%d，b：%d\n",a,b);
		crossover1(&population[a],&population[b],&nextPop[i],&nextPop[i+1]);
		if(i!= POP_SIZE){
			for(j=0;j<MAX_NUM;j++){
				nextPop[i].chrom[j] = rand()%2;
			}
		}
	}






	// ****************************************************************************************

	// 突然変異
	// ****************************************************************************************

	for(i=1;i<POP_SIZE;i++){
		mutate(&nextPop[i]);
	}


	// ****************************************************************************************

	// 次世代を現世代に変更
	for(i = 0; i < POP_SIZE; i++)
		population[i] = nextPop[i];
}

// ランキング選択
int rankingSelect()
{
	int i = 0, num;

	// ****************************************************************************************
	num = rand() % ((POP_SIZE*(POP_SIZE+1)/2)+1);
	for(i = 0;i < POP_SIZE;i++){

		if((POP_SIZE-i) >= num){
			break;
		}
		num -= POP_SIZE-i;
	}
	//printf("numの値：%d\n",num);
	//printf("iの値：%d\n",i);
	return i;
	// ****************************************************************************************
}

// トーナメント選択
int tournamentSelect()
{
	int i, j, ret = -1;
	double min;

	// ****************************************************************************************
	// ret = -1;
	// min = DBL_MAX;
	// for(i=0;i<TOURNAMENT_SIZE;i++){
	// 	j = rand()% POP_SIZE -1 + 1;
	// 	 if(population[j].fitness<min){
	// 		 ret = j;
	// 		 min = population[j].fitness;
	// 	 }
	// }
	//
	//
	//
	// ****************************************************************************************
	return ret;
}

// 1点交叉
// p1 : 対象の親個体1
// p2 : 対象の親個体2
// c1 : 対象の子個体1
// c2 : 対象の子個体2
void crossover1(Individual *p1, Individual *p2, Individual *c1, Individual *c2)
{
	int point, i;

	// ****************************************************************************************
	point = rand() % (MAX_NUM-2+1);
	for(i=0;i <= point;i++){
		c1 -> chrom[i] = p1 -> chrom[i];
		c2 -> chrom[i] = p2 -> chrom[i];
	}
	for(i=point+1;i < MAX_NUM;i++){
		c1 -> chrom[i] = p2 -> chrom[i];
		c2 -> chrom[i] = p1 -> chrom[i];
	}



	// ****************************************************************************************
}

// 2点交叉
// p1 : 対象の親個体1
// p2 : 対象の親個体2
// c1 : 対象の子個体1
// c2 : 対象の子個体2
void crossover2(Individual *p1, Individual *p2, Individual *c1, Individual *c2)
{
	int point1, point2, tmp, i;

	// ****************************************************************************************
	// point1 = rand()%MAX_NUM-2+1;
	// do{
	// 	point2 = rand()%MAX_NUM-2+1;
	// }while (point1 == point2);
	// if (point1>point2){
	// 	tmp = point1;
	// 	point1 = point2;
	// 	point2 = tmp;
	// }
	// for(i=0;i<=point1;i++){
	// 	c1 -> chrom[i] = p1 ->chrom[i];
	// 	c2 -> chrom[i] = p2 ->chrom[i];
	//
	// }
	// for(i=point1;i<=point2;i++){
	// 	c1 -> chrom[i] = p2 ->chrom[i];
	// 	c2 -> chrom[i] = p1 ->chrom[i];
	// }
	// for(i=point2+1;i<MAX_NUM;i++){
	// 	c1 -> chrom[i] = p1 ->chrom[i];
	// 	c2 -> chrom[i] = p2 ->chrom[i];
	// }
	//
	//


	// ****************************************************************************************
}

// 一様交叉
// p1 : 対象の親個体1
// p2 : 対象の親個体2
// c1 : 対象の子個体1
// c2 : 対象の子個体2
void crossoverU(Individual *p1, Individual *p2, Individual *c1, Individual *c2)
{
	int i;

	// ****************************************************************************************
	// for(i=0;i<MAX_NUM;i++){
	// 	if(rand()%2 == 1){
	// 		c1 -> chrom[i] = p1 ->chrom[i];
	// 		c2 -> chrom[i] = p2 ->chrom[i];
	// 	}else{
	// 		c1 -> chrom[i] = p2 ->chrom[i];
	// 		c2 -> chrom[i] = p1 ->chrom[i];
	// 	}
	// }



	// ****************************************************************************************
}

// 突然変異
// c : 対象の子個体
void mutate(Individual *c)
{
	int i;

	// ****************************************************************************************

	for(i = 0;i < MAX_NUM;i++){
		if(MUTATE_PROB > rand() % 2){
			c -> chrom[i] = 1-c -> chrom[i];
		}
	}


	// ****************************************************************************************
}

// 配列population[lb]～population[ub]をfitnessの昇順に整列（クイックソート）
// lb: 整列する範囲の下限の添字
// ub: 整列する範囲の上限の添字
void sort(int lb, int ub)
{
	int i, j, k;
	double pivot;
	Individual tmp;

	if(lb < ub) {
		k = (lb + ub) / 2;
		pivot = population[k].fitness;
		i = lb;
		j = ub;
		do {
			while(population[i].fitness < pivot)
				i++;
			while(population[j].fitness > pivot)
				j--;
			if(i <= j) {
				tmp = population[i];
				population[i] = population[j];
				population[j] = tmp;
				i++;
				j--;
			}
		} while(i <= j);
		sort(lb, j);
		sort(i, ub);
	}
}

// 結果表示
// best : 最良個体
void printResult(Individual *best)
{
	int i;
	FILE* fp;

	fp = fopen("result.txt", "w");
	if(fp == 0) {
		printf("Cannot open result.txt for output.\n");
		exit(1);
	}
	fprintf(fp, "集合A：");
	for(i = 0; i < MAX_NUM; i++) {
		if(best->chrom[i] == 1)
			fprintf(fp, "%d ", i+1);
	}
	fprintf(fp, "\n集合B：");
	for(i = 0; i < MAX_NUM; i++) {
		if(best->chrom[i] == 0)
			fprintf(fp, "%d ", i+1);
	}

	fprintf(fp, "\n平方根和の差：%f\n", best->fitness);
	fprintf(fp, "最良個体の適応度：%f\n", best->fitness);
	fprintf(fp, "処理時間：%f秒\n", comptime);
	fclose(fp);
	fp = fopen("result_list.csv","r");
	if(fp == NULL){
		fp = fopen("result_list.csv","w");
		fprintf(fp,"処理時間\t最良個体の適応度\t平方根和の差\n");
	}
	fclose(fp);
	fp = fopen("result_list.csv","a");
	fprintf(fp, "%f\t%f\t%f\n", comptime,best->fitness,dSumOfSquare);
	fclose(fp);


}

void culculate(individual *best){
	int i,count1,count2;
	double v1,v2,sum1,sum2; //sum1：集合Aの平方根和，sum2：集合Bの平方根和

	count1 = 0; //集合Aが何個あるか
	count2 = 0; //集合Bが何個あるか
	sum1 = 0;
	sum2 = 0;
	dSumOfSquare = 0;

	for(i=0;i<MAX_NUM;i++){
		if(best->chrom[i] == 1){
			v1 = sqrt((double)i+1);
			count1 +=1;
			sum1 += v1;
		}
	}
	for(i=0;i<MAX_NUM;i++){
		if(best->chrom[i] == 0){
			v2 = sqrt((double)i+1);
			count2 +=1;
			sum2 += v2;
		}
	}
	printf("sum1の値は：%f,sum2の値は%f\n",sum1,sum2);
	dSumOfSquare = fabs(sum1 - sum2);
	printf("平方根和の差：%f\n",dSumOfSquare);

}
