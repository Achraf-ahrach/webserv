#include "../hpp/Client.hpp"

void	Client::Response::postMethodeResponse()
{
	if (me->_flags.canReadInputFile)
	{
		char	buf[5002];
		inputFile.read(buf, 5000);

		int	howMuchRead = inputFile.gcount();
		std::stringstream ss;
		ss<< std::hex << howMuchRead;
		me->_finalAnswer.append(ss.str().append("\r\n"));

		buf[howMuchRead] = '\r';
		buf[howMuchRead + 1] = '\n';

		me->_finalAnswer.append(buf, howMuchRead + 2);

		if (howMuchRead != 5000 && howMuchRead)
		{
			me->_finalAnswer.append("0\r\n");
			inputFile.close();
			me->_flags.isResponseFinished = true;
		}
		return ;
	}

	if (me->_codeStatus != 200 && me->_codeStatus != 201 )
	{
		responseError();
	}
	else
	{
		if (me->_configData->allLocations[me->_locationKey].cgi.empty() == 0)
		{
			/*run cgi and get response based on it*/
		}
		else if (me->_configData->allLocations[me->_locationKey].canUpload)
		{
			/*201 created*/
		}
	}
}

void	Client::Response::responseError(void)
{
	std::stringstream ss;
	ss << "HTTP/1.1 " << me->_codeStatus << " " << me->_mimeError->statusCode[me->_codeStatus] << "\r\n";
	ss << "Content-Type: " << "text/html" << "\r\n";
	ss << "Content-Length: " << me->_mimeError->errors[me->_codeStatus].size() << "\r\n";
	ss << "Connection: " << "Close" << "\r\n" ; //later check if should check request
	ss << "\r\n";
	ss <<  me->_mimeError->errors[me->_codeStatus] << "\r\n";
	// me->_flags.removeMe = true;

	me->_finalAnswer = ss.str();
}
