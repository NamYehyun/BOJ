#include <iostream>

using namespace std;


const int N_MAX = 64;


bool** new_image(int size) {
    bool** image = new bool*[size];
    for (int i = 0; i < size; ++i) {
        image[i] = new bool[size];
    }

    return image;
}


void print_image(bool** image, int size) {
    cout << "size: " << size << '\n';
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            cout << image[row][col] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return;
}


void free_image(bool** image, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] image[i];
    }
    delete[] image;

    image = nullptr;

    return;
}

bool is_uniform(bool** image, int size) {
    bool key = image[0][0];
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (image[row][col] != key) {
                return false;
            }
        }
    }

    return true;
}


void div_image(bool** image, int size, bool** sub1, bool** sub2, bool** sub3, bool** sub4) {
    int sub_size = size/2;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (row < sub_size && col < sub_size) {
                sub1[row][col] = image[row][col];
            } else if (row < sub_size && col >= sub_size) {
                sub2[row][col - sub_size] = image[row][col];
            } else if (row >= sub_size && col < sub_size) {
                sub3[row - sub_size][col] = image[row][col];
            } else if (row >= sub_size && col >= sub_size) {
                sub4[row - sub_size][col - sub_size] = image[row][col];
            }
        }
    }

    return;
}


string compress(bool** image, int size) {
    // print_image(image, size);

    if (is_uniform(image, size)) {
        return to_string(image[0][0]);
    }

    int sub_size = size/2;
    bool** sub1 = new_image(sub_size);
    bool** sub2 = new_image(sub_size);
    bool** sub3 = new_image(sub_size);
    bool** sub4 = new_image(sub_size);

    div_image(image, size, sub1, sub2, sub3, sub4);

    string result = "(" + compress(sub1, size/2) + compress(sub2, size/2) + compress(sub3, size/2) + compress(sub4, size/2) + ")";

    free_image(sub1, size/2);
    free_image(sub2, size/2);
    free_image(sub3, size/2);
    free_image(sub4, size/2);

    return result;
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    bool** image = new_image(n);

    for (int row = 0; row < n; ++row) {
        string line;
        cin >> line;
        for (int col = 0; col < n; ++col) {
            image[row][col] = line[col] - '0';
        }
    }

    cout << compress(image, n) << endl;

    free_image(image, n);

    return EXIT_SUCCESS;
}

