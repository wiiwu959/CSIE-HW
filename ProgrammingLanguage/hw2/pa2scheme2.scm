(define (dbl_atm atm list1)
  (if (not (null? list1)) 
    (if (list? list1)
      (if (list? (car list1))
        (list (append (dbl_atm atm (car list1)) (dbl_atm atm (cdr list1))))
        (append (dbl_atm atm (car list1)) (dbl_atm atm (cdr list1)))
      )
      (if (eq? atm list1)
        (append (list atm) (list atm))
        (list list1)
      )
    )
    '()
  )
)

(dbl_atm 'a '(a (b c a (a d))) )