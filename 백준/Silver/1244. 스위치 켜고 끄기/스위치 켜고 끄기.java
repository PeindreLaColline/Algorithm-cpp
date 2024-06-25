import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        boolean[] v = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            int tmp = sc.nextInt();
            v[i] = (tmp == 1);
        }

        int pn = sc.nextInt(); // people num
        for (int i = 0; i < pn; i++) {
            int gen = sc.nextInt();
            int num = sc.nextInt();
            if (gen == 1)
                man(v, num);
            else
                woman(v, num, n);
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(v[i] ? "1" : "0");
            if (i == n)
                System.out.println();
            else if (i % 20 == 0)
                System.out.println();
            else
                System.out.print(" ");
        }

        sc.close();
    }

    private static void woman(boolean[] v, int num, int n) {
        int cs = num;
        int ce = num;
        while (true) {
            if (cs <= 0 || ce > n) {
                cs++;
                ce--;
                break;
            }
            if (v[cs] == v[ce]) {
                cs--;
                ce++;
                continue;
            } else {
                cs++;
                ce--;
                break;
            }
        }
        if (cs >= ce) {
            v[num] = !v[num];
        } else {
            for (int i = cs; i <= ce; i++) {
                v[i] = !v[i];
            }
        }
    }

    private static void man(boolean[] v, int idx) {
        if (idx == 0) {
            v[0] = !v[0];
            return;
        }
        int i = 1;
        while (true) {
            if (idx * i > v.length - 1)
                break;
            v[idx * i] = !v[idx * i];
            i++;
        }
    }
}
