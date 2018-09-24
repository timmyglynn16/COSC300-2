
public class insertSort {
    public static void main(String[] args) { 
        
        int[] a = { 7, 8, 9, 10, 1, 6, 2, 4, 3, 5};

        long startTimeODD = System.nanoTime();
        insertSort(a, a.length);
        long endTimeODD = System.nanoTime();
        long totalTimeODD = endTimeODD - startTimeODD;

        for(int i : a)
        System.out.print(i + " ");
        System.out.println();

        System.out.println("Elapsed Time: " + totalTimeODD/1000 + " seconds");

    } 
    
    static void insertSort(int[] a, int num) {
        
        for(int j=1; j<num; j++) {
            
            int t = a[j], i = j;
            
            while(i > 0 && a[i-1] > t) {
                
                a[i] = a[i-1];
                i--;
            
            }
            
            a[i] = t;
            
        }
            
    }
}

