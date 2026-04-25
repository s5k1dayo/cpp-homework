#include<iostream>
using namespace std;
/*int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (x == a[mid])return mid;
        else if (x > a[mid])low = mid;
        else high = mid;
    }
    return -1;
}*/




int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;
    while (low + 1 != high) {
        int mid = (low + high) / 2;
        if (x >= a[mid])low = mid;
        else high = mid;
    }
    if (x == a[low])return low;
    else return -1;
}


/*int binarySearch(int a[], int n, int x) {
    int low = 0, high = n - 1;
    while (low < high - 1) {
        int mid = (low + high) / 2;
        if (x < a[mid])high = mid;
        else low = mid;
    }
    if (x == a[low])return low;
    else return -1;
}
*/

/*int binarySearch(int a[], int n, int x) {
    if (n > 0 && x >= a[0]) {
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (x < a[mid])high = mid - 1;
            else low = mid;
        }
        if (x == a[low])return low;
    }
    return -1;
}
 */

int main(){
    int a[5]={1,2,3,4,5};
    int ans=binarySearch(a,5,1);
    cout<<ans;
}