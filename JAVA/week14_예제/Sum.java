class SumThread extends Thread{

    private int lo, hi;
    private int[] arr;
    int ans = 0;

    public SumThread(int[] arr, int lo, int hi){

        this.lo = lo;
        this.hi = hi;
        this.arr = arr;
    }

    @Override
    public void run(){
        for(int i=lo; i<=hi; i++){
            ans += arr[i];
        }
    }
}

public class Sum{
    public static void main(String args[]) throws InterruptedException{
        int[] arr = new int[10];
        for(int i=0; i<arr.length; i++){
            arr[i] = i;
        }
        int len = arr.length;
        int ans = 0;

        SumThread t1, t2;
        t1 = new SumThread(arr, 0, 4);
        t1.start();
        t2 = new SumThread(arr, 5, 9);
        t2.start();

        t1.join();
        ans += t1.ans;
        t2.join();
        ans += t2.ans;

        System.out.println("Sum: "+ans);
    }
}