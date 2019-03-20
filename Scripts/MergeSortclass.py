class MergeSortClass:
    def __init__(self, arr):
        print("Sorting...\n")
        self.arr = arr
        self.mergeSort(arr)

    def mergeSort(self, arr):
        if len(arr) > 1:
            m = int(len(arr)/2)
            # print(m)
            L = arr[:m]
            R = arr[m:]
            
            self.mergeSort(L)
            self.mergeSort(R)

            i, j, k = 0, 0, 0
            # or i = j = k = 0

            while i < len(L) and j < len(R):
                if L[i] <= R[j]: 
                    arr[k] = L[i] 
                    i += 1 
                else:
                    arr[k] = R[j] 
                    j+= 1 
                k += 1 
        
            while i < len(L): 
                arr[k] = L[i] 
                i += 1 
                k += 1 
        
            while j < len(R): 
                arr[k] = R[j] 
                j += 1 
                k += 1 
    
    def printArray(self, A, size):
        for i in range(size): 
            print(A[i]) 

if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7] 
    arr_size = len(arr) 
    to_be_sorted_array = MergeSortClass(arr)
    print("Sorted array is \n") 
    to_be_sorted_array.printArray(arr, arr_size)