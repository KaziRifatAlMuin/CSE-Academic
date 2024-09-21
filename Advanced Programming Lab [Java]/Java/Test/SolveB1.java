import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.util.Arrays.sort;
import java.util.Scanner;

public class SolveB1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-- > 0){
            int n, m, q;
            n = scanner.nextInt();
            m = scanner.nextInt();
            q = scanner.nextInt();
            int[] b = new int[m];
            int[] a = new int[q];
            for(int i = 0; i < m; i++){
                b[i] = scanner.nextInt();
            }
            for(int i = 0; i < q; i++){
                a[i] = scanner.nextInt();
            }
            sort(b);
            for(int x : a){
                if(b[0] > x && b[m-1] > x){
                    System.out.println(b[0] - 1);
                }
                else if(b[0] < x && b[m-1] < x){
                    System.out.println(n - b[m-1]);
                }
                else{
                    int l = b[0], r = b[m-1];
                    int mid = (l + r) / 2;
                    int move = abs(mid - x);
                    int x1 = l + move, x2 = r - move;
                    System.out.println(move + min(abs(x1 - mid), abs(x2 - mid)));
                }
            }
        }
        scanner.close();
    }
}
