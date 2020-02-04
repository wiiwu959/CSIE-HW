(define (revert list1) 
  (if (= 1 (length list1))
    list1
    (append (revert (cdr list1)) (list (car list1)))
  )
)

(define (palindrome list1)
  (append list1 (revert list1))
)

(palindrome '(a b c))