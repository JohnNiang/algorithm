import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

/**
 * A1062: Talent and Virtue
 * <https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944>
 * 
 * @author johnniang
 *
 */
public class Main {

	/** Class for buffered reading int and double values */
	static class Reader {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		/** call this method to initialize reader for InputStream */
		static void init(InputStream input) {
			reader = new BufferedReader(new InputStreamReader(input));
			tokenizer = new StringTokenizer("");
		}

		/** get next word */
		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				// TODO add check for EOF if necessary
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static void close() throws IOException {
			if (reader != null) {
				reader.close();
			}
		}
	}

	public static void main(String[] args) throws IOException {
		Reader.init(System.in);

		int N = Reader.nextInt();
		int L = Reader.nextInt();
		int H = Reader.nextInt();

		int M = N;

		List<Student> students = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			// Input student
			Student student = new Student();
			student.name = Reader.next();
			student.virtue = Reader.nextInt();
			student.talent = Reader.nextInt();

			student.total = student.talent + student.virtue;

			if (student.virtue < L || student.talent < L) {
				student.level = 5;
				M--;
			} else if (student.virtue >= H && student.talent >= H) {
				student.level = 1;
			} else if (student.virtue >= H && student.talent < H) {
				student.level = 2;
			} else if (student.virtue >= student.talent) {
				student.level = 3;
			} else {
				student.level = 4;
			}

			students.add(student);
		}

		Reader.close();

		Collections.sort(students, buildSort());

		System.out.println(M);
		for (int i = 0; i < M; i++) {
			System.out.println(students.get(i).name + " " + students.get(i).virtue + " " + students.get(i).talent);
		}
	}

	static Comparator<Student> buildSort() {
		return (left, right) -> {
			if (left.level != right.level) {
				return left.level - right.level;
			}

			if (left.total != right.total) {
				return right.total - left.total;
			}

			if (left.virtue != right.virtue) {
				return right.virtue - left.virtue;
			}

			return left.name.compareTo(right.name);
		};
	}

	static class Student {
		private String name;
		private int virtue;
		private int talent;

		private int total;
		private int level;
	}
}
