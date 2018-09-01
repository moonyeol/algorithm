import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Josephus suicide = new Josephus();
        int n,m,k;
		Scanner s = new Scanner(System.in);

        n = s.nextInt();
        m = s.nextInt();
        k = s.nextInt();
        suicide.setNumOfPeople(n);
        suicide.setNumOfStart(m);
        suicide.addPeople();
        suicide.display();

        suicide.setCountNum(k);
        suicide.execute();

    }

}