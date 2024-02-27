#include <bits/stdc++.h>

using namespace std;

struct DoseOption {
    double volume; // 实际药液容量
    double syringeSize; // 注射器容量
};

// 递归函数来生成组合
void GenerateCombinations(const vector<DoseOption>& doseOptions, vector<DoseOption>& currentCombination, int start, int end, int index, int r) {
    if (index == r) {
        // 对于每个组合，计算在不同注射次数下的单次注射剂量
        for (int i = 10; i <= 180; i += 10) {
            double totalVolume = 0;
            for (int j = 0; j < r; ++j) {
                totalVolume += currentCombination[j].volume;
            }
            double singleDose = totalVolume / i;
            cout << "组合:";
            for (int j = 0; j < r; ++j) {
                cout << " " << currentCombination[j].volume << "/" << currentCombination[j].syringeSize << "ml";
            }
            cout << ", 注射次数: " << i << ", 单次注射剂量: " << fixed << setprecision(2) << singleDose << " ml" << endl;
        }
        return;
    }

    // 替换组合的下一个元素并递归
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        currentCombination[index] = doseOptions[i];
        GenerateCombinations(doseOptions, currentCombination, i + 1, end, index + 1, r);
    }
}

int main() {
    vector<DoseOption> doseOptions = {
        {0.8, 1},
        {2, 3},
        {3, 3},
        {4, 5},
        {5, 5}
    };

    // 从1到5生成所有可能的组合
    for (int r = 1; r <= 5; r++) {
        vector<DoseOption> currentCombination(r);
        GenerateCombinations(doseOptions, currentCombination, 0, doseOptions.size() - 1, 0, r);
    }

    return 0;
}
