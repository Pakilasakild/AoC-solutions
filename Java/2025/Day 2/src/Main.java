import java.io.*;
import java.util.*;
import java.util.regex.*;

public class Main {

    // Pattern: block repeated exactly twice
    private static final Pattern TWICE_PATTERN = Pattern.compile("(\\d+)(\\1)");

    // Pattern: block repeated at least twice
    private static final Pattern AT_LEAST_TWICE_PATTERN = Pattern.compile("(\\d+)(\\1)+");

    // Pattern to extract ranges a-b
    private static final Pattern RANGE_PATTERN = Pattern.compile("(\\d+)\\s*-\\s*(\\d+)");

    private static boolean isTwice(long x) {
        return TWICE_PATTERN.matcher(Long.toString(x)).matches();
    }

    private static boolean isAtLeastTwice(long x) {
        return AT_LEAST_TWICE_PATTERN.matcher(Long.toString(x)).matches();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Part (1 or 2): ");
        int part = sc.nextInt();

        String line;
        try (BufferedReader br = new BufferedReader(new FileReader("U2.txt"))) {
            line = br.readLine();
        } catch (IOException e) {
            return;
        }

        Matcher m = RANGE_PATTERN.matcher(line);
        long sum = 0;

        while (m.find()) {
            long a = Long.parseLong(m.group(1));
            long b = Long.parseLong(m.group(2));

            for (long x = a; x <= b; x++) {
                if (part == 1) {
                    if (isTwice(x)) {
                        sum += x;
                    }
                } else {
                    if (isAtLeastTwice(x)) {
                        sum += x;
                    }
                }
            }
        }
        System.out.println(sum);
    }
}
