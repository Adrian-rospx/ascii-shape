# ASCII shape rasterizer

Written in C++.

Done using a **DDA line drawing algorithm** along with 
the **scanline polygon fill algorithm** in order to draw 
any polygon, both convex and concave with quite a nice accuracy.

I've added all 8 basic terminal colors.

Shapes can be defined by modifying the x and y values of each vertex.

Current example:
```
                                       -
       $$$$$$$$$$$$$$$$$$$
       $..................$
       $..................$
       $....$$$$$$$$$$.....$
       $....$         $.....$
      $.....$         $.....$
      $.....$ $$$$$$$$$$.....$
      $.....$ $...............$
      $.....$ $................$
      $.....$ $$$$$$$$$$$......$
      $....$             $......$
      $....$              $......$
      $....$               $.....$
     $.....$               $......$
     $.....$                $......$
     $.....$                 $.....$
     $$$$$$$                  $$$$$$$

-
```