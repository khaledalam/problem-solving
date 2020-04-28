import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;
import java.util.TreeMap;
import java.util.*;

// Author: Khaled Alam

class MyTools{
	static String [] isValidLinePhonebook(String line) {
		
		if(line.strip().length() == 0)
			return null;
		
		String[] lineArgs = line.split(" ", -1);
		
		if(lineArgs.length != 2)
			return null;
		
		String num = lineArgs[1];
		
		int idx = 0;
		if(num.charAt(0) == '+')
			idx++;
		
		if(!num.substring(idx).matches("[0-9]+"))
			return null;
		
		return lineArgs;
	}
	
static String [] isValidLineOutgoingCalls(String line) {
		
		if(line.strip().length() == 0)
			return null;
		
		String[] lineArgs = line.split(" ", -1);
		
		if(lineArgs.length != 2)
			return null;
		
		String num = lineArgs[0];
		String calls = lineArgs[1];
		
		int idx = 0;
		if(num.charAt(0) == '+')
			idx++;
		
		if(!num.substring(idx).matches("[0-9]+"))
			return null;
		

		if(!calls.matches("[0-9]+"))
			return null;
		
		if(PhoneBook.normalizePhoneNumber(num) == null)
			return null;
		
		return lineArgs;
	}
}


class OutgoingCalls {

	static <K, V extends Comparable<? super V>> SortedSet<Map.Entry<K, V>> entriesSortedByValues(Map<K, V> map) {
		SortedSet<Map.Entry<K, V>> sortedEntries = new TreeSet<Map.Entry<K, V>>(new Comparator<Map.Entry<K, V>>() {
			@Override
			public int compare(Map.Entry<K, V> e1, Map.Entry<K, V> e2) {
				int res = e2.getValue().compareTo(e1.getValue());
				return res != 0 ? res : 1;
			}
		});
		sortedEntries.addAll(map.entrySet());
		return sortedEntries;
	}

	private TreeMap<String, Integer> pairs = new TreeMap<String, Integer>();

	public OutgoingCalls(File file) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		String line = null;

		while ((line = br.readLine()) != null) {
			
			if(MyTools.isValidLineOutgoingCalls(line) == null)
				continue;
			
			String[] lineArgs = line.split(" ", -1);
			
			String number = lineArgs[0];
			Integer calls = Integer.valueOf(lineArgs[1]);
			
			pairs.put(PhoneBook.normalizePhoneNumber(number), calls);
		}
		br.close();
	}

	public void printTopOutgoingCalls() {

		Integer limit = 5;
		for (Map.Entry<String, Integer> entry : entriesSortedByValues(pairs)) {
			if(limit-- <= 0)
				break;
			String key = entry.getKey();
			Integer value = entry.getValue();
			System.out.println(key + " => " + value + " (calls)");
		}
		System.out.println();
	}
}


class PhoneBook {

	TreeMap<String, String> phoneBook;

	public PhoneBook(File file) throws IOException {
		phoneBook = new TreeMap<>();
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		String line = null;

		while ((line = br.readLine()) != null) {

			String[] ret = MyTools.isValidLinePhonebook(line); 
			
			if(ret == null)
				continue;
			
			String name = ret[0], num = ret[1];
			
			String number = normalizePhoneNumber(num);
			if (number != null) {
				addPhone(name, number);
			}
		}
		br.close();
	}

	public void addPhone(String name, String number) {
		if(PhoneBook.normalizePhoneNumber(number) != null)
			phoneBook.put(name, number);
	}

	public void removePhoneByName(String name) {
		phoneBook.remove(name);
	}

	public String getPhoneByName(String name) {
		return phoneBook.get(name);
	}

	public void printPhoneBook() {
		for (Map.Entry<String, String> phonePair : phoneBook.entrySet()) {
			System.out.println(phonePair.getKey() + " " + phonePair.getValue());
		}
		System.out.println();
	}

	static public String normalizePhoneNumber(String number) {

		if (number.length() > 14) {
			return null;
		}

		Integer last7 = Integer.valueOf(number.substring(number.length() - 7, number.length()));
		if (last7 < 2000000) {
			return null;
		}

		List<Integer> ops = Arrays.asList(87, 88, 89);
		
		Integer operator = Integer.valueOf(number.substring(number.length() - 9, number.length() - 7));
		if (!ops.contains(operator)) {
			return null;
		}

		String code = number.substring(0, number.length() - 9);

		if (number.startsWith("00") && code.length() == 5) {
			number = number.replaceFirst("00", "+");
		} else if (number.startsWith("0") && code.length() == 1) {
			number = number.replaceFirst("0", "+359");
		} else if (!number.startsWith("+359")) {
			return null;
		}

		return number;
	}

	public static void main(String... args) throws IOException {

//    	File folder = new File("./");
//    	File[] listOfFiles = folder.listFiles();
//    	for (File file : listOfFiles) {
//    	    if (file.isFile()) {
//    	        System.out.println(file.getName());
//    	    }
//    	}
//    	
		File filePhonebook = new File("phonebook.txt");
		PhoneBook phoneBook = new PhoneBook(filePhonebook);

		System.out.println("Phone Books:");
		phoneBook.printPhoneBook();
		
		// => Remove by value
//		phoneBook.removePhoneByName("Khaled_Alam");
//		phoneBook.printPhoneBook();
		
		// => Try add wrong inputs
//		phoneBook.addPhone("Khaled", "+355878123456");
		
		
//		=> Try add correct inputs
//		phoneBook.addPhone("Khaled", "+359883120454");
		
//		System.out.println("Phone Books after changes:");
//		phoneBook.printPhoneBook();
		
		
		File fileOutgoingCalls = new File("outgoing_calls.txt");
		OutgoingCalls o = new OutgoingCalls(fileOutgoingCalls);

		System.out.println("Top 5 outgoing calls:");
		o.printTopOutgoingCalls();
	}
}
