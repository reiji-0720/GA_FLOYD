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
#define POP_SIZE			1000	// 個体集団内の個体の数
#define ELITE				1		// エリート保存戦略で残す個体の数
#define TOURNAMENT_SIZE		10		// トーナメント選択で無作為抽出する個体の数
#define MUTATE_PROB			0.01	// 突然変異確率
#define MAX_NUM				64		// フロイド問題におけるN

// 構造体の定義
typedef struct individual {
	double fitness;			// 適応度
	int chrom[MAX_NUM];		// 染色体
} Individual;

// グローバル変数の宣言
Individual population[POP_SIZE];	// 個体集団
Individual nextPop[POP_SIZE];		// 個体集団
float comptime;						// 処理時間

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




	// ****************************************************************************************
}

// 次世代生成
void newGeneration()
{
	int i, j, a, b;

	// エリート保存戦略
	// ****************************************************************************************




	// ****************************************************************************************

	// ランキング選択＆一点交叉
	// ****************************************************************************************




	// ****************************************************************************************

	// 突然変異
	// ****************************************************************************************




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



	return i;
	// ****************************************************************************************
}

// トーナメント選択
int tournamentSelect()
{
	int i, j, ret = -1;
	double min;

	// ****************************************************************************************




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




	// ****************************************************************************************
}

// 突然変異
// c : 対象の子個体
void mutate(Individual *c)
{
	int i;

	// ****************************************************************************************




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
	fprintf(fp, "\n最良個体の適応度：%f\n", best->fitness);
	fprintf(fp, "処理時間：%f秒\n", comptime);
	fclose(fp);
}
