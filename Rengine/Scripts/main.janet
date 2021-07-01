#(import Ren)

(def planet "hehe")

(print planet)

(Ren/custom_print "lol")

#(import 
#  (chibi))
# ; (Scripts EventTypes))
#
#(define (test-func)
#  (%Custom-Print "hello"))
#
#(define (displayln string)
#  (display string)
#  (newline))
#
#(define (say-hello)
#  (displayln "The say hello function was called!"))
#
#(define (callback1)
#  (displayln "callback"))
#
#(define (init event_manager)
#  (Register-Callback event_manager 21 callback1))
#
#(define (draw)
#  (displayln "drawing"))
#
#(define (update delta_time)
#  (displayln "updating")
#  (displayln delta_time)
#  (test-func))
#
# have self be set by c and point to this scripts object
# define allcall backs at end of script
# (register-callback 'draw
#    (lambda (renderer)
#            (display 'test)
#            )))