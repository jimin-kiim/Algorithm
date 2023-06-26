//
// Created by 김지민 on 2023/06/26.
//

#include <iostream>
using namespace std;

// when using cout and printf alternately,
// both of C stream and C++ stream is used
// and they are synchronized -> takes much time
int main_default(void) {
    cout << "11111\n";
    printf("22222\n");
    cout << "33333\n";
}
/** result
 * 11111
 * 22222
 * 33333
 */

int main_modified(void) {
    ios::sync_with_stdio(0); // disconnecting C stream and C++ stream
    cout << "11111\n";
    printf("22222\n");
    cout << "33333\n";
}
/** result
 * 22222
 * 11111
 * 33333
 */
