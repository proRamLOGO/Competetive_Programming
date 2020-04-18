import java.text.CharacterIterator;
import java.text.StringCharacterIterator;

class Solution {
    public boolean backspaceCompare(String S, String T) {
        
        Stack<Character> s = new Stack<>(), t = new Stack<>() ;
        
        CharacterIterator its = new StringCharacterIterator(S) ;
        CharacterIterator itt = new StringCharacterIterator(T) ;
        
        while ( its.current() != CharacterIterator.DONE ) {
            if ( its.current() != '#' ) {
                s.push(its.current()) ;
            } else if ( !s.empty() ) {
                s.pop() ;
            }
            its.next() ;
        }
        
        while ( itt.current() != CharacterIterator.DONE ) {
            if ( itt.current() != '#' ) {
                t.push(itt.current()) ;
            } else if ( !t.empty() ) {
                t.pop() ;
            }
            itt.next() ;
        }
        
        boolean ans = ( s.size() == t.size() ) ;
        
        if ( ans == false )
            return false ;
        
        while ( !s.empty() ) {
            if ( s.peek() != t.peek() ) {
                ans = false ;
                break ;
            }
            s.pop() ;
            t.pop() ;
        }
        
        return ans ;
        
    }
}