int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int complement = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == complement) {
        count++;
        int left_ptr = mid - 1;
        while (left_ptr >= left && arr[left_ptr] == complement) {
          count++;
          left_ptr--;
        }
        int right_ptr = mid + 1;
        while (right_ptr <= right && arr[right_ptr] == complement) {
          count++;
          right_ptr++;
        }
        break;
      } else if (arr[mid] < complement) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_val = arr[left];
      int right_val = arr[right];
      int left_count = 0;
      int right_count = 0;
      while (arr[left] == left_val) {
        left++;
        left_count++;
      }
      while (arr[right] == right_val) {
        right--;
        right_count++;
      }
      count += left_count * right_count;
      }else if (sum < value) {
      left++;
      } else {
      right--;
    }
  }
  return count;
}



