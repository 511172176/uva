import java.util.*;
import java.util.Stack;

/**
 * uva747
 */
public class uva727 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
        //sc.nextLine();
        while(n-- > 0) {
            //sc.nextLine();
            Stack<String> st = new Stack<>();
            StringBuilder s = new StringBuilder();
            boolean firstLine = true;
            while (sc.hasNextLine()) {
                String c = sc.nextLine();
                /*if(c.isEmpty())
                    //break;
                    continue;*/
                if (c.isEmpty()) {
                    if (!firstLine) break; 
                    continue;
                }
                firstLine = false;

                if (Character.isDigit(c.charAt(0))) {
                    s.append(c);
                } else {
                    if (c.equals("(")) {
                        st.push(c);
                    } else if (c.equals("*") || c.equals("/")) {
                        while (!st.empty() && (st.peek().equals("*") || st.peek().equals("/"))) {
                            s.append(st.pop());
                        }
                        st.push(c);
                    } else if (c.equals("+") || c.equals("-")) {
                        while (!st.empty() && (st.peek().equals("*") || st.peek().equals("/") || st.peek().equals("+") || st.peek().equals("-"))) {
                            s.append(st.pop());
                        }
                        st.push(c);
                    } else if (c.equals(")")) {
                        while (!st.empty() && !st.peek().equals("(")) {
                            s.append(st.pop());
                        }
                        if (!st.empty() && st.peek().equals("(")) {
                            st.pop();
                        }
                    }
                }
            }
            while (!st.empty()) {
                s.append(st.pop());
            }
            System.out.println(s.toString());
            if(n>0)
                System.out.println();
        }
        sc.close();
    }
}
