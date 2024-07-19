#ifndef _linePID_hpp_
#define _linePID_hpp_
class linePID {
    private:
        float kp, ki, kd;
        float error, lastError, integral, derivative;
        float output;
    public:
        linePID(float kp, float ki, float kd);
        int parseError();
        float getOutput(float input);
        void reset();
};

#endif