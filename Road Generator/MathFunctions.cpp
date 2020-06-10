//
//  MathFunctions.cpp
//  Road Generator
//
//  Created by Michael Schuff on 6/3/20.
//  Copyright © 2020 Michael Schuff. All rights reserved.
//

#include "MathFunctions.hpp"

using namespace std;

namespace MathFunctions {
vector<vector<double>> ReducedRowEchelonForm(vector<vector<double>> vect) {
    int columns = vect[0].size();
    int rows = vect.size();
    double leading;
    double head;
    for (int i = 0; i < columns; i++) {
        for (int j = i; j < rows; j++) {
            leading = vect[j][i];
            if (leading != 0) {
                for (int k = 0; k < columns; k++) {
                    vect[j][k] /= leading;
                }
                for (int l = 0; l < rows; l++) {
                    head = vect[l][i];
                    if (l != j) {
                        for (int k = 0; k < columns; k++) {
                            vect[l][k] -= head * vect[j][k];
                        }
                    }
                }
                
                if (j < vect.size() && i < vect.size()) {
                    swap(vect[i], vect[j]);
                }
                
                break;
            }
        }
    }
    return vect;
}

vector<double> RREFOutput(vector<vector<double>> vect) {
    vector<double> out;
    for (int i = 0; i < vect.size(); i++) {
        out.push_back(vect[i][vect[i].size() - 1]);
    }
    return out;
}

double RandomRange(double lower, double upper) {
    return (upper - lower) * ((double) rand() / RAND_MAX) + lower;
}

int RandomRange(int lower, int upper) {
    return (rand() % (upper - lower)) + lower;
}
}
