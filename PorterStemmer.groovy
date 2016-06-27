/* 
Author Dhaval Dave : https://in.linkedin.com/in/davedhaval87
Run this groovy code with giving File of words to stem as command line input.
ex :$ groovy PorterStemmer.groovy abc.txt

You can change input method with simple modification in program.
Porter stemmer in Groovy. The original paper is in
Porter, 1980, An algorithm for suffix stripping, Program, Vol. 14,
no. 3, pp 130-137,
See also http://www.tartarus.org/~martin/PorterStemmer

for any bug Please mail to : davedhaval87@gmail.com

*/

class PorterStemmer {
 def b = "" //buffer for word to be stemmed
 def k = 0
 def k0 = 0
 def j = 0 //j is a general offset into the string

 def cons(i) {
  if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
   return 0
  if (b[i] == 'y')
   if (i == k0)
    return 1
   else
    return (!cons(i - 1))
  return 1
 }
 def m() {
   def n = 0
   def i = k0
   while (1) {
    if (i > j) {
     return n
    }
    if (!cons(i)) {
     break
    }
    i = i + 1
   }
   i = i + 1
   while (1) {
    while (1) {
     if (i > j) {
      return n
     }
     if (cons(i)) {
      break
     }
     i = i + 1
    }
    i = i + 1
    n = n + 1
    while (1) {
     if (i > j) {
      return n
     }
     if (!cons(i)) {
      break
     }
     i = i + 1
    }
    i = i + 1
   }
  } //def m
 def vowelinstem() {
   for (int i = k0; i < j + 1; i++) {
    if (!cons(i)) {
     return 1
    }
   }
   return 0
  } //def vowelinstem

 def doublec(j) {
   if (j < k0 + 1) {
    return 0
   }
   if (b[j] != b[j - 1]) {
    return 0
   }
   return cons(j)
  } // def doublec

 def cvc(i) {
   if (i < k0 + 2 || !cons(i) || cons(i - 1) || !cons(i - 2)) {
    return 0
   }
   def ch = b[i]
   if (ch == 'w' || ch == 'x' || ch == 'y') {
    return 0
   }
   return 1
  } //def cvc

 def ends(s) {
   def len = s.length()
   if (s[len - 1] != b[k]) {
    return 0
   }
   def o = k - len + 1
   if (o < 0) {
    return 0
   }
   if (len > o) {
    return 0
   }

   for (int tempI = 0; tempI < len; tempI++) {
    if (b[o + tempI] != s.charAt(tempI)) {
     return 0
    }
   }
   j = k - len
   return 1
  } //def ends

 def setto(s) {
   def len = s.length()
   def o = j + 1
   for (int tempI = 0; tempI < len; tempI++) {
    b[o + tempI] = s.charAt(tempI)
   }
   k = j + len;
  } //setto

 def r(s) {
   if (m() > 0) {
    setto(s)
   }
  } //r(s)
 def printVariable() {
  println k
 }
 def step1ab() {

   if (b[k] == 's') {
    if (ends('sses')) {
     k = k - 2
    } else if (ends('ies')) {
     setto('i')
    } else if (b[k - 1] != 's') {
     k = k - 1
    }
   }
   if (ends('eed')) {
    if (m() > 0) {
     k = k - 1
    }
   } else if (ends('ed') || ends('ing') && vowelinstem()) {
    k = j
    if (ends("at")) {
     setto('ate')
    } else if (ends('bl')) {
     setto('ble')
    } else if (ends('iz')) {
     setto('ize')
    } else if (doublec(k)) {
     k = k - 1
     def ch = b[k]
     if (ch == 'l' || ch == 's' || ch == 'z') {
      k = k + 1
     }
    } else if (m() == 1 && cvc(k)) {
     setto('e')
    }
   }
  } //set1ab
 def step1c() {
   if (ends("y") && vowelinstem()) {
    b[k] = 'i'
   }

  } //step1c

 def step2() {
   switch (b[k - 1]) {
    case 'a':
     if (ends("ational")) {
      r("ate");
      break;
     }
     if (ends("tional")) {
      r("tion");
      break;
     }
     break;
    case 'c':
     if (ends("enci")) {
      r("ence");
      break;
     }
     if (ends("anci")) {
      r("ance");
      break;
     }
     break;
    case 'e':
     if (ends("izer")) {
      r("ize");
      break;
     }
     break;
    case 'l':
     if (ends("bli")) {
      r("ble");
      break;
     }
     if (ends("alli")) {
      r("al");
      break;
     }
     if (ends("entli")) {
      r("ent");
      break;
     }
     if (ends("eli")) {
      r("e");
      break;
     }
     if (ends("ousli")) {
      r("ous");
      break;
     }
     break;
    case 'o':
     if (ends("ization")) {
      r("ize");
      break;
     }
     if (ends("ation")) {
      r("ate");
      break;
     }
     if (ends("ator")) {
      r("ate");
      break;
     }
     break;
    case 's':
     if (ends("alism")) {
      r("al");
      break;
     }
     if (ends("iveness")) {
      r("ive");
      break;
     }
     if (ends("fulness")) {
      r("ful");
      break;
     }
     if (ends("ousness")) {
      r("ous");
      break;
     }
     break;
    case 't':
     if (ends("aliti")) {
      r("al");
      break;
     }
     if (ends("iviti")) {
      r("ive");
      break;
     }
     if (ends("biliti")) {
      r("ble");
      break;
     }
     break;
    case 'g':
     if (ends("logi")) {
      r("log");
      break;
     }
   }
  } //step2

 def step3() {
   switch (b[k]) {
    case 'e':
     if (ends("icate")) {
      r("ic");
      break;
     }
     if (ends("ative")) {
      r("");
      break;
     }
     if (ends("alize")) {
      r("al");
      break;
     }
     break;
    case 'i':
     if (ends("iciti")) {
      r("ic");
      break;
     }
     break;
    case 'l':
     if (ends("ical")) {
      r("ic");
      break;
     }
     if (ends("ful")) {
      r("");
      break;
     }
     break;
    case 's':
     if (ends("ness")) {
      r("");
      break;
     }
     break;
   }

  } //step3
 def step4() {
   switch (b[k - 1]) {
    case 'a':
     if (ends("al")) break;
     return;
    case 'c':
     if (ends("ance")) break;
     if (ends("ence")) break;
     return;
    case 'e':
     if (ends("er")) break;
     return;
    case 'i':
     if (ends("ic")) break;
     return;
    case 'l':
     if (ends("able")) break;
     if (ends("ible")) break;
     return;
    case 'n':
     if (ends("ant")) break;
     if (ends("ement")) break;
     if (ends("ment")) break;
     if (ends("ent")) break;
     return;
    case 'o':
     if (ends("ion") && j >= 0 && (b[j] == 's' || b[j] == 't')) break;
     if (ends("ou")) break;
     return;
    case 's':
     if (ends("ism")) break;
     return;
    case 't':
     if (ends("ate")) break;
     if (ends("iti")) break;
     return;
    case 'u':
     if (ends("ous")) break;
     return;
    case 'v':
     if (ends("ive")) break;
     return;
    case 'z':
     if (ends("ize")) break;
     return;
    default:
     return;
   }
   if (m() > 1) k = j;

  }//step4

 def step5() {
   j = k
   if (b[k] == 'e') {
    def a = m()
    if (a > 1 || a == 1 && !cvc(k - 1)) k--;
   }
   if (b[k] == 'l' && doublec(k) && m() > 1) k--;
  } //step5

 def stem(p, i, j) {
   b = p
   k = j
   k0 = i
   if (k < k0 + 1) {
    return b;
   }
   if (k > 1) {
    step1ab()
    step1c()
    step2()
    step3()
    step4()
    step5()
   }
   return b[k0..k]
  } //stem

 public static void main(String[] args) {

  def output = ''
  def ipFile = new File(args[0])
  def line
  ipFile.withReader{ reader ->
        while((line = reader.readLine())!=null){
                if ("${line}" == ""){
                        break
                }
                else{
                	line = line.toLowerCase();
                	String[] words = line.split(" ");
                	def len = words.size()
                	def wordLen = 0
                	for (def tempi = 0; tempi < len; tempi++) {
					   wordLen = words[tempi].length()
					   output += new PorterStemmer().stem(words[tempi], 0, wordLen - 1)
					   output += ','
					}
					
                }
        }

  }
  println output
 }
}
