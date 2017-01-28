#include <cstdio>
#include <iostream>

using namespace std;

string flip_quadtree(string image) {
    unsigned len = image.size();
    unsigned pos[5];
    int curpos = 0;
    int num_skip = 0;

    if (image == "w" || image == "b")
        return image;

    for (int i = 1; i < len; ++i) {
        char curc = image.at(i);

        if (num_skip == 0)
            pos[curpos++] = (unsigned) i;
        else
            num_skip--;

        if (curc == 'x')
            num_skip += 4;
    }

    string slice[4];
    pos[4] = len;

    for (int j = 0; j < 4; ++j)
        slice[j] = flip_quadtree(image.substr(pos[j], pos[j + 1] - pos[j]));

    return "x" + slice[2] + slice[3] + slice[0] + slice[1];
}

int main(int argc, char **argv) {
    int TC;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        string image;
        cin >> image;
        cout << flip_quadtree(image) << endl;
    }

    return 0;
}
