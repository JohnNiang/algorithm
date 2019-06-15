import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * A1012: The Best Rank
 * <https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480>
 * 
 * @author johnniang
 *
 */
public class Main {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int N = sc.nextInt();
			int M = sc.nextInt();

			List<Student> students = new ArrayList<>();

			for (int i = 0; i < N; i++) {
				Student student = new Student();
				student.number = sc.next();
				student.c = sc.nextInt();
				student.m = sc.nextInt();
				student.e = sc.nextInt();
				student.a = (student.c + student.m + student.e) / 3;
				students.add(student);
			}

			// Sort
			students.sort(cSort());
			Map<String, Integer> cRankMap = getRankMap(students);

			students.sort(mSort());
			Map<String, Integer> mRankMap = getRankMap(students);

			students.sort(eSort());
			Map<String, Integer> eRankMap = getRankMap(students);

			students.sort(aSort());
			Map<String, Integer> aRankMap = getRankMap(students);

			for (int i = 0; i < M; i++) {
				String number = sc.next();
				Integer cRank = cRankMap.get(number);
				if (cRank == null) {
					System.out.println("N/A");
					break;
				}

				int mRank = mRankMap.get(number);
				int eRank = eRankMap.get(number);
				int aRank = aRankMap.get(number);

				if (eRank < mRank) {
					System.out.println((eRank + 1) + " E");
				} else if (mRank < cRank) {
					System.out.println((mRank + 1) + " M");
				} else if (cRank < aRank) {
					System.out.println((cRank + 1) + " C");
				} else {
					System.out.println((aRank + 1) + " A");
				}
			}

		}
	}

	static Map<String, Integer> getRankMap(List<Student> students) {
		if (students == null || students.isEmpty()) {
			return Collections.emptyMap();
		}
		Map<String, Integer> rankMap = new HashMap<>();
		for (int i = 0; i < students.size(); i++) {
			rankMap.put(students.get(i).number, i);
		}
		return rankMap;
	}

	static void print(List<Student> students) {
		students.forEach(student -> {
			System.out.println(student.number + " " + student.c + " " + student.m + " " + student.e + " " + student.a);
		});
	}

	static Comparator<Student> cSort() {
		return (left, right) -> {
			return right.c - left.c;
		};
	}

	static Comparator<Student> mSort() {
		return (left, right) -> {
			return right.m - left.m;
		};
	}

	static Comparator<Student> eSort() {
		return (left, right) -> {
			return right.e - left.e;
		};
	}

	static Comparator<Student> aSort() {
		return (left, right) -> {
			return right.a - left.a;
		};
	}

	static class Student {
		String number;
		int c;
		int m;
		int e;
		int a;
	}
}
