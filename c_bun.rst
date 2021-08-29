# [allow (unused_imports)] 
use std :: collections :: *; 
# [allow (unused_imports)] 
use std :: io :: prelude :: *; 
# [allow (unused_imports)] 
use std :: prelude :: *;
 
fn main ( )  { 
    let stack_size =  104 _857_600 ;  // 100 MB 
    let thd = std :: thread :: Builder :: new ( ) . stack_size ( stack_size ) ; 
    thd. spawn ( || solve ( ) ) . unwrap ( ) . join ( ) . unwrap ( ) ; 
}
 
fn solve ( )  { 
    let stdin  = std :: io :: stdin ( ) ; 
    let mut bytes = std :: io :: Read :: bytes ( std :: io :: BufReader :: new ( stdin . lock ( ) ) ) ; 
    let mut next = move ||  ->  String  {
        bytes
            ... by_ref ( ) 
            . map ( | c | c. unwrap ( ) as char ) 
            . skip_while ( | c | c. is_whitespace ( ) ) 
            . take_while ( | c |  ! c. is_whitespace ( ) ) 
            . collect ( ) 
    } ; 
    let ( n , k) :  ( usize , usize )  =  ( next ( ) . parse ( ) . unwrap ( ) , next ( ) . parse ( ) . unwrap ( ) ) ;
 
    let mut parent = Vec :: with_capacity ( n ) ; 
    parent. push ( 0 ) ; 
    parent. extend ( ( 0 .. n  -  1 ) . map ( | _ | next ( ) . parse :: < usize > ( ) . unwrap ( )  -  1 ) ) ;
 
    let mut graph = vec ! [ vec ! [ ] ; n ] ; 
    for  ( child ,  & parent ) in parent [ 1 .. ] . iter ( ) . enumerate ( )  { 
        graph [ parent ] . push ( child +  1 ) ; 
    }
 
    let mut height = vec ! [ 0 _usize ; n ] ; 
    let ( _ ,  ( mut v1 , mut v2 , h ) )  = dfs ( & graph ,  0 ,  0 , k ,  & mut height ,  & parent ) ;
 
    if h ! =  0  { 
        while height [ v1 ]  ! = h { v1 = parent [ v1 ] ;  } 
        while height [ v2 ]  ! = h { v2 = parent [ v2 ] ;  } 
        println ! ( "YES \ n {} \ n {} {}" , h , v1 + 1 , v2 + 1) 
    }  else  { 
        println ! ( "NO" ) 
    } 
}
 
type Ans =  ( ( usize , usize ) ,  ( usize , usize , usize ) ) ;
 
fn dfs ( 
    graph :  & Vec < Vec < usize >>, 
    v : usize , 
    h : usize , 
    k : usize , 
    mut height :  & mut Vec < usize >, 
    parent :  & Vec < usize >, 
)  ->  Ans  { 
    height [ v ]  = h ; 
    if graph [ v ]... is_empty ( )  { 
        return  ( ( h , v ) ,  ( 0 ,  0 ,  0 ) ) ; 
    }
 
    let mut vmax =  [ ( 0 , 0 ) ;  2 ] ; 
    let mut ans =  ( 0 ,  0 ,  0 ) ; 
    for  & child in & graph [ v ]  { 
        let ( vm , other )  = dfs ( graph , child , h +  1 , k ,  & mut height , parent) ;
 
        if vm > vmax [ 0 ]  { 
            vmax [ 1 ]  = vmax [ 0 ] ; 
            vmax [ 0 ]  = vm ; 
        }  else  if vm > vmax [ 1 ]  { 
            vmax [ 1 ]  = vm ; 
        }
 
        if ans.2 < other.2 { 
            ans = other ; 
        } 
    }
 
    if vmax [ 1 ] .0  ! =  0  && h +  2  <= k { 
        let ( a , b )  =  ( vmax [ 0 ] .1 , vmax [ 1 ] .1 ) ;
 
        let m = std :: cmp :: min ( height [ a ] , height [ b ] ) ; 
        let n = std :: cmp :: min ( ( k + h )  >>  1 , m ) ;
 
        if a ! = b && n > ans.2 { 
            ans =  ( a , b , n ) ; 
        } 
    }
 
    ( vmax [ 0 ] , ans ) 
}
