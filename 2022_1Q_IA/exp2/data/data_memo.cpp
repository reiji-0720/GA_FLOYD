#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>





int main(){
	int i ,j , k, l, m,n,o,p,q,r;
	FILE* fp;
	fp = fopen("data.csv", "r");

	if(fp == NULL){

		fp = fopen("data.csv","w");
		fprintf(fp,"世代交代数\t個体集団内の個体の数\tエリート保存戦略で残す個体の数\tトーナメント選択で無作為抽出する個体の数\t突然変異確率\tフロイド問題におけるN\t選択方式\t交叉方式\n");
	}
	if(fp == 0) {
		printf("Cannot open result.txt for output.\n");
		exit(1);
	}
	fclose(fp);
	fp = fopen("data.csv","w");
	if(fp == 0) {
		printf("Cannot open data.csv for output.\n");
		exit(1);
	}


	for (i=0; i <3;i++){
		switch(i){
			case 0:
				fprintf(fp, "10\t");
				break;
			case 1:
				fprintf(fp, "100\t");
				break;
			default:
				fprintf(fp, "100\t");
				break;
		}

		for(j=0;j<3;j++){
			switch(j){
				case 0:
					fprintf(fp, "10\t");
					break;
				case 1:
					fprintf(fp, "100\t");
					break;
				default:
					fprintf(fp, "100\t");
					break;
			}
			for(k=0;k<3;k++){
				switch(k){
					case 0:
						fprintf(fp, "1\t");
						break;
					case 1:
						fprintf(fp, "2\t");
						break;
					default:
						fprintf(fp, "5\t");
						break;
				}
				for(l=0;l<3;l++){
					switch(l){
						case 0:
							fprintf(fp, "1\t");
							break;
						case 1:
							fprintf(fp, "10\t");
							break;
						default:
							fprintf(fp, "50\t");
							break;
					}
					for(o=0;o<4;o++){
						switch(k){
							case 0:
								fprintf(fp, "0.01\t");
								break;
							case 1:
								fprintf(fp, "0.05\t");
								break;
							case 2:
								fprintf(fp, "0.1\t");
							default:
								fprintf(fp, "0.5\t");
								break;
						}
						for(p=0;p<3;p++){
							switch(k){
								case 0:
									fprintf(fp, "32\t");
									break;
								case 1:
									fprintf(fp, "64\t");
									break;
								default:
									fprintf(fp, "128\t");
									break;
							}
							for(q=0;q<2;q++){
								switch(k){
									case 0:
										fprintf(fp, "ランダム選択方式\t");
										break;
									default:
										fprintf(fp, "トーナメント選択方式\t");
										break;
								}
								for(r=0;r<3;r++){
									switch(k){
										case 0:
											fprintf(fp, "１点交叉方式\t");
											break;
										case 1:
											fprintf(fp,"2点交叉方式\t");

										default:
											fprintf(fp, "一様交叉方式\t");
											break;
									}
									fprintf(fp, "\n");
								}
							}
						}
					}
				}
			}

		}

	}
}
