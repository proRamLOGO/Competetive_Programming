/** HalfAdder.java represents a binary half-adder.  It calculates the
 *  output from boolean expressions that represent the logical circuit
 *  for a binary half-adder.
 */

class HalfAdder
{
 /** Default constructor
  *  Postcondition: attribute variables myInput1 and myInput2 are 
  *                   set to false
  */
 public HalfAdder() 
 {
   myInput1 = myInput2 = false;
 }

 /** setInput1() and setInput2() set the two binary inputs of the half-adder.
  *  Receive:       digit, an integer
  *  Precondition:  digit is a binary digit (0 or 1)
  *  Postcondition: attribute variables myInput1 and myInput2 are
  *                  set to this bit.
  */

 public void setInput1(int digit)
 {
   if (isBinary(digit))
     myInput1 = toBoolean(digit);
   else
   { 
     System.err.println("setInput1(int): non-binary input: " + digit);
	  System.exit(1);
   }
 }
 
 public void setInput2(int digit)
 {
   if (isBinary(digit))
     myInput2 = toBoolean(digit);
   else
   {
     System.err.println("setInput2(int): non-binary input: " + digit);
	  System.exit(1);
   }
 }

 /** toString() converts outputs of binary half-adder to a String
  *     suitable for output to the screen.
  *  Return: string containing sum and carry bits
  */

 public String toString()
 {
   return " sum: " + sum() + ", carry: " + carry();
 }

 /** sum() and carry() compute the outputs of binary half-adder.
  *  Return: sum and carry bits
  */

 public int sum()
 {
   return toInt( (myInput1 || myInput2) && !(myInput1 && myInput2) );
 }

 public int carry()
 { 
   return toInt( myInput1 && myInput2 );
 }

 // -- Utility methods:
 /** isBinary() checks if digit is a binary digit (0 or 1).
  *  Receive:  digit, an int
  *  Return:   true if digit is a bit, false otherwise
  */
  public static boolean isBinary(int digit)
  {
    return (digit == 0 || digit == 1);
  }

 /** toBoolean() converts a bit to boolean value (0 -> false, 1 -> true).
  *  Receive: bit, an int
  *  Return:  true if bit is 1, false if bit is 0
  */
  public static boolean toBoolean(int digit)
  {
    return !(digit == 0);
  }

 /** toInt() converts boolean value to a bit (false -> 0, true -> 1).
  *  Receive: input, a boolean
  *  Return:  1 if input it true, false if it is 0
  */
 public static int toInt(boolean input)
 {
   return ((input == true) ? 1 : 0);
 }

 private boolean myInput1,      // boolean representation, to ease
                 myInput2;      //  the sum and carry computations
}

