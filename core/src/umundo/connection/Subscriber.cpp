/**
 *  @file
 *  @author     2012 Stefan Radomski (stefan.radomski@cs.tu-darmstadt.de)
 *  @copyright  Simplified BSD
 *
 *  @cond
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the FreeBSD license as published by the FreeBSD
 *  project.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  You should have received a copy of the FreeBSD license along with this
 *  program. If not, see <http://www.opensource.org/licenses/bsd-license>.
 *  @endcond
 */

#include "umundo/connection/Subscriber.h"
#include "umundo/common/Factory.h"
#include "umundo/common/UUID.h"

namespace umundo {

int SubscriberImpl::instances = -1;

SubscriberImpl::SubscriberImpl() : _receiver(NULL) {
	instances++;
}

SubscriberImpl::~SubscriberImpl() {
	instances--;
}

shared_ptr<Configuration> SubscriberConfig::create() {
	return shared_ptr<SubscriberConfig>(new SubscriberConfig());
}

Subscriber::Subscriber(const string& channelName, Receiver* receiver) {
	_impl = boost::static_pointer_cast<SubscriberImpl>(Factory::create("subscriber"));
	SubscriberStub::_impl = _impl;
	_config = boost::static_pointer_cast<SubscriberConfig>(Factory::config("subscriber"));
//	_config->channelName = channelName;
//	_config->receiver = receiver;
	_impl->setChannelName(channelName);
	_impl->init(_config);
	_impl->setReceiver(receiver);
}

Subscriber::~Subscriber() {
}

Subscriber::Subscriber(const std::string& channelName) {
	_impl = boost::static_pointer_cast<SubscriberImpl>(Factory::create("subscriber"));
	SubscriberStub::_impl = _impl;
	_config = boost::static_pointer_cast<SubscriberConfig>(Factory::config("subscriber"));
//	_config->channelName = channelName;
//	_config->receiver = receiver;
	_impl->setChannelName(channelName);
	_impl->init(_config);
}

}