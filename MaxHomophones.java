import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class MaxHomophones 
{
    public static void main(String[] args)
    {
        OALDictionary<String, String> PDict = new OALDictionary<String, String>();
        File file = new File("cmudict.0.7a.txt");

        Scanner lengthVal = new Scanner(System.in);
        int lineNum = lengthVal.nextInt();
        int count = 0;

        ArrayList<String> pronun = new ArrayList<String>();
        try {
			Scanner scanner = new Scanner(file);
			while (scanner.hasNextLine() && count<lineNum) {
				String line = scanner.nextLine();
				if (line.substring(0, 3).equals(";;;"))
					continue; // skip comment lines
				Pronunciation p = new Pronunciation(line);
					PDict.insert(p.getPhonemes(), p.getWord());
                    pronun.add(p.getPhonemes());
                    count++;
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

        UALDictionary<String, ArrayList<String>> homophoneHolder = new UALDictionary<String, ArrayList<String>>();
        ArrayList<String> usedKeys = new ArrayList<String>();
        int contained = 0;
        for (String p : pronun)
        {
            if (!usedKeys.contains(p)) 
            {
                homophoneHolder.insert(p, PDict.findAll(p));
                usedKeys.add(p);
            }
        }

        for (ArrayList<String> sizeComp : homophoneHolder.values())
        {
            if (sizeComp.size() > contained) {contained = sizeComp.size();}
        }

        System.out.println(contained);
        for (ArrayList<String> printer : homophoneHolder.values())
        {
            if(printer.size() == contained) 
            {
                for (int x = 0; x < contained; x++) {System.out.println(printer.get(x));}
                System.out.println();
            }
        }
    }
}
