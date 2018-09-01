public class Josephus {

    private int numOfPeople; // number of people in a circle
    private int countNum; // number used for counting off
    private int startNum;
    private Node head;
    private Node tail;
    CircularList circle;

    public Josephus() {
        circle = new CircularList();
        numOfPeople = 0;
        countNum = 0;

    }

    public void setNumOfPeople(int x) {
        numOfPeople = x;

    }

    public int getNumOfPeople() {
        return numOfPeople;
    }

    public void setCountNum(int x) {
        countNum = x;
    }

    public void setNumOfStart(int x) {
        startNum = x;
    }
    
    public int getCountNum() {
        return countNum;
    }

    public void addPeople() {
        for (int i = 1; i <= numOfPeople; i++) {
            circle.insert(i);
        }
    }

    public void move() {

        for (int i = 1; i < countNum; i++) {
            tail = head;
            head = head.next;
        }

        System.out.print(head.iData+ " ");

    }
    
    public void start() {

        for (int i = 1; i < startNum; i++) {
            tail = head;
            head = head.next;
        }
        System.out.print(head.iData + " ");
        circle.delete(head.iData);
        tail = tail.next;
        head = head.next;
        numOfPeople--;
    }

    public void execute() {
        tail = null;
        head = circle.getFirst();
        start();
        while (numOfPeople != 1) {
            move();
            circle.delete(head.iData);
            tail = tail.next;
            head = head.next;
            numOfPeople--;
        }
        System.out.print(head.iData+ " ");
    }

    public void display() {
        System.out.print("");
        circle.displayList();
    }

}