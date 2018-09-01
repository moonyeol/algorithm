public class CircularList {

    private Node first;
    private Node last;
    private Node current;
    private int count; // total items in the list
    public CircularList getCurrent;

    public CircularList() {
        first = null;
        last = null;
        current = null;
        count = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public void step() {
        current = current.next;
    }

    public Node getCurrent() {
        return current;
    }

    public Node getFirst() {
        return first;
    }

    public void insert(int x) {
        Node newNode = new Node(x);

        if (isEmpty()) {
            first = newNode;
            current = first;
        } else {
            current.next = newNode;
        }

        newNode.next = first;
        last = newNode;
        step();
        count++;
    }

    public boolean search(int x) {
        Node search = first;
        int y = 0;

        while (search.iData != x && y < count) {
            search = search.next;
            y++;
        }

        if (search.iData == x) {
            System.out.println("Found the value: " + search.iData);
            return true;
        } else {
            System.out.println("Value not found in list");
            return false;
        }

    }

    public void delete(int x) {
        Node prev = first;
        Node curr = first.next;

        while (curr.iData != x) {
            prev = curr;
            curr = curr.next;

        }

        if (count == 1) {
            first = null;
            count--;
        } else if (curr == first) {
            prev.next = curr.next;
            first = curr.next;
            count--;
        } else {
            prev.next = curr.next;
            count--;
        }

    }

    public void displayList() {
        int x = 0;
        Node printer = first;

        while (x < count) {
            printer.displayNode();
            printer = printer.next;
            x++;
        }
        System.out.println("");

    }

}