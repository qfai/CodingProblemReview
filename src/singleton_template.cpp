class Logger{
	public:
		static Logger Instance(){
			static Logger thelogger;
			return thelogger;
		}
		virtual void Write(char const *logline);
		/*virtual bool destrucor(){
			if(!m_pInstance)
			delete m_pInstance;
			m_pInstance=NULL;
		}
		*/
	private:
		Logger();
		Logger(Logger const&);
		Logger& operator=(Logger const&);
		~Logger();
		//static Logger* m_pInstance;
		//other data field
};