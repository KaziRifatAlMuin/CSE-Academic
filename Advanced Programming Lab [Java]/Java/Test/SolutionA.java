import java.util.Scanner;

public class SolutionA {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // Number of test cases
        long st = System.currentTimeMillis(); // Start time
        
        while (t-- > 0) {
            int n = scanner.nextInt();
            String ans = "";
            String tmp = "aeiou";
            
            for (int i = 5; i >= 1; i--) {
                int c = n / i;
                n -= c;
                for (int j = 0; j < c; j++) {
                    ans += tmp.charAt(i - 1);
                }
            }
            System.out.println(ans);
        }
        
        long et = System.currentTimeMillis(); // End time
        System.err.println("[Time : " + (et - st) + " ms]");
        
        scanner.close();
    }
}