package org.umundo.protobuf;

// Generated by the umundo protocol buffer compiler. DO NOT EDIT!
// source: ChatS11N.proto

import org.umundo.rpc.ServiceDescription;
import org.umundo.rpc.ServiceStub;

public class ChatServiceStub extends ServiceStub {
	public ChatServiceStub(ServiceDescription svcDesc) {
		super(svcDesc);
		_rpcSub.registerType(org.umundo.protobuf.ChatS11N.Void.class);
	}

	public org.umundo.protobuf.ChatS11N.Void receive(org.umundo.protobuf.ChatS11N.ChatMsg in) throws InterruptedException {
		return (org.umundo.protobuf.ChatS11N.Void) callStubMethod("receive", in, "ChatMsg", "Void");
	}

	public org.umundo.protobuf.ChatS11N.Void join(org.umundo.protobuf.ChatS11N.ChatMsg in) throws InterruptedException {
		return (org.umundo.protobuf.ChatS11N.Void) callStubMethod("join", in, "ChatMsg", "Void");
	}

	public org.umundo.protobuf.ChatS11N.Void leave(org.umundo.protobuf.ChatS11N.ChatMsg in) throws InterruptedException {
		return (org.umundo.protobuf.ChatS11N.Void) callStubMethod("leave", in, "ChatMsg", "Void");
	}

}
