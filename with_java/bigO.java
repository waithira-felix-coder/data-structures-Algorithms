public class bigO{

  public void log(int[] numbers) {
    //big O(1) the runtime for this algorithm
    System.out.println(numbers[0]);
    System.out.println(numbers[0]);
  }
}
//Program2
public void log(int[] numbers) {
  //runtime complexity: O(n) where n is the size of input. So as n grows the cause of the algorithm also grows linearly
  for(int i=0; i<numbers.length; i++)
    System.out.println(numbers[i]);
}