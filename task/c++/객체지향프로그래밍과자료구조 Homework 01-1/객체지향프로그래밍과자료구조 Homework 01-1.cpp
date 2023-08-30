/**
* 파일명: ""
* 프로그램의 목적 및 기본 기능:
*- 이 프로그램은 input.txt에서 임의의 개수의 자연수들을 입력받아 fileInputData함수를
*  통해 자연수의 개수를 리턴하고 자연수들을 int형 배열에 저장하고,
*  getStatistics_fileOut함수를 통해 이전에 구한 자연수의 개수만큼의 반복문을 통해
*  자연수와 min, max, sum, avg, var, std_dev등의 문제에서 요구하는 값들을
*  output.txt에 출력한다.
* 
* 프로그램 작성자: 이세용 (2023년 8월 30일),
* 최종 수정 및 보완 : Version 1.0, 2023년 8월 30일 (이세용).
*
* =========================================================================================
* 프로그램 수정/보완 이력
* =========================================================================================
* 프로그램 수정/ 보완작업자      일자      수정/보완 내용
* 이세용           2023/08/30    v1.0
*
*
* =========================================================================================
*/

#include <iostream>
#include <fstream>

#define INPUT_NAME "input.txt"
#define OUTPUT_NAME "output.txt"
#define MAX_NUM 100
using namespace std;

int fileInputData(ifstream& fin, int* data_array, int max_num_data);
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout);

int main()
{
    ifstream fin;
    ofstream fout;
    int array[MAX_NUM];
    int count;

    fin.open(INPUT_NAME);
    if (fin.fail())
    {
        cout << "fail to open (" << INPUT_NAME << ")" << endl;
        return 0;
    }
    count = fileInputData(fin, array, MAX_NUM);

    fout.open(OUTPUT_NAME);
    if (fout.fail())
    {
        cout << "fail to open (" << OUTPUT_NAME << ")" << endl;
        return 0;
    }
    getStatistics_fileOut(array, count, fout);
    fin.close();
    fout.close();
    return 0;
}

int fileInputData(ifstream& fin, int* data_array, int max_num_data)
{
    int count = 0;
    while (count < max_num_data && fin >> data_array[count])
    {
        count++;
    }
    return count;
}
void getStatistics_fileOut(int* data_array, int num_data, ofstream& fout)
{
    int min, max;
    double sum = 0, avg, var, diff, sq_diff_sum=0.0, std_dev;
    min = INT_MAX;
    max = INT_MIN;

    fout << "Total " << num_data << " integer data : {";
    for (int i = 0; i < num_data; i++) {
        fout << " " << data_array[i];
        if (i != num_data-1)
            fout << ", ";
        else
            fout << " ";
        sum += data_array[i];
        if (min > data_array[i])
            min = data_array[i];
        if (max < data_array[i])
            max = data_array[i];
    }
    avg = sum / num_data;
    for (int i = 0; i < num_data; i++) {
        diff = data_array[i] - avg;
        sq_diff_sum += diff * diff;
    }
    var = sq_diff_sum / num_data;
    std_dev = sqrt(var);

    fout << "}" << endl;
    fout << "min(" << min << "), ";
    fout << "max(" << max << "), ";
    fout << "sum(" << sum << "), ";
    fout << "avg(" << avg << "), ";
    fout << "var(" << var << "), ";
    fout << "std_dev(" << std_dev << ")";
}