#include <iostream>
#include <cstdlib>

enum class vacant{
    Allowed,
    Forbidden
};

using namespace std;

int main(){
    vacant** pointers;
    cout << "Dimensions?" << endl;
    int dim;
    cin >> dim;
    pointers = new vacant*[dim];
    for(int i = 0; i < dim; i++)
        pointers[i] = new vacant[dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            pointers[i][j] = vacant::Allowed;
        }
    }
    return 0;
}