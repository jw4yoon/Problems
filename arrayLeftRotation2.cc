vector<int> array_left_rotation(vector<int> a, int n, int k) {
    if (n == 0) {
        return a;
    }
    if (k >= n) { // if the number of rotations is bigger than the size of array
        k = k % n;
    }
    
    int curIndex = 0;
    int newIndex = 0;
    int count = 0;
    int temp;
    int temp2;
    int initIndex = 0; // indicates the initial index when starting over
    bool startOver = true; // bool indicating start
    while(count < n) {
        newIndex = curIndex - k;
        if (newIndex < 0) {
            newIndex += n;
        }
        if (startOver) {
            initIndex = curIndex;
            temp = a[newIndex];
            a[newIndex] = a[curIndex];
            curIndex = newIndex;
            startOver = false;
        } else {
            temp2 = a[newIndex];
            a[newIndex] = temp;
            temp = temp2;
            curIndex = newIndex;
            if (count != n - 1 && newIndex == initIndex) { // to avoid repetition of choosing indexes, need to check if we've already accessed the newIndex
                curIndex += 1;
                startOver = true;
            }
        }
        ++count;
    }
    return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
