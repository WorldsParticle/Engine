#ifndef     __EVENT_HPP__
#define     __EVENT_HPP__




namespace   WorldParticles
{

    namespace   Engine
    {

        class Event {

        public :
            Event();

            enum {
                MouseClick,
                MouseMove,
                Key
            };

            bool isConsumed() const;
            void consume();

        private :
            bool    _consumed;
        };
    }
}

#endif // __EVENT_HPP__
