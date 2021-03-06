package SpMVAccel

import Chisel._
import TidbitsOCM._
import TidbitsDMA._
import TidbitsStreams._

class CacheDataReadWritePort(lineSize: Int, addrBits: Int) extends Bundle {
  val addr = UInt(INPUT, width=addrBits)
  val dataIn = UInt(INPUT, width=lineSize)
  val writeEn = Bool(INPUT)
  val dataOut = UInt(OUTPUT, width=lineSize)
  override def clone = { new CacheDataReadWritePort(lineSize,addrBits).asInstanceOf[this.type] }
}

class CacheDataReadPort(lineSize: Int, addrBits: Int) extends Bundle {
  val addr = UInt(INPUT, width=addrBits)
  val dataOut = UInt(OUTPUT, width=lineSize)
  override def clone = { new CacheDataReadPort(lineSize,addrBits).asInstanceOf[this.type] }
}

class CacheReadPortIF(p: SpMVAccelWrapperParams) extends Bundle {
  // read request port
  val req = Decoupled(UInt(width=p.ptrWidth)).flip
  // read response data
  val rsp = Decoupled(UInt(width=p.opWidth))

  override def clone = { new CacheReadPortIF(p).asInstanceOf[this.type] }
}

class CacheWritePortIF(p: SpMVAccelWrapperParams) extends Bundle {
  // write request port
  val req = Decoupled(new OperandWithID(p.opWidth, p.ptrWidth)).flip
  override def clone = { new CacheWritePortIF(p).asInstanceOf[this.type] }
}

class SinglePortCacheIF(val p: SpMVAccelWrapperParams) extends Bundle {
  // interface towards processing element:
  val read = new CacheReadPortIF(p)
  val write = new CacheWritePortIF(p)

  // interface towards main mem
  val mem = new GenericMemoryMasterPort(p.toMRP())

  val writeComplete = Bool(OUTPUT)

  val base = UInt(INPUT, 32)
  val startInit = Bool(INPUT)
  val startWrite = Bool(INPUT)
  val done = Bool(OUTPUT)

  // init indicator and cache stat outputs
  val readCount = UInt(OUTPUT, 32)
  val readMissCount = UInt(OUTPUT, 32)
  val writeCount = UInt(OUTPUT, 32)
  val writeMissCount = UInt(OUTPUT, 32)
  val conflictMissCount = UInt(OUTPUT, 32)
  val cacheState = UInt(OUTPUT, 32)

  override def clone = { new SinglePortCacheIF(p).asInstanceOf[this.type] }
}

class FullTagResponse(indBits: Int, tagBits: Int, dataBits: Int) extends Bundle {
  val ind = UInt(width = indBits)
  val reqCMS = Bool()
  val reqTag = UInt(width = tagBits)
  val rspTag = UInt(width = tagBits)
  val rspValid = Bool()
  val rspData = UInt(width = dataBits)

  override def clone = {
    new FullTagResponse(indBits, tagBits, dataBits).asInstanceOf[this.type]
  }
}

class NBCacheReadPortIF(p: SpMVAccelWrapperParams) extends Bundle {
  // read request port
  val req = Decoupled(new OperandWithID(p.opWidth, p.ptrWidth)).flip
  // read response data
  val rsp = Decoupled(new OperandWithID(2*p.opWidth, p.ptrWidth))

  override def clone = { new NBCacheReadPortIF(p).asInstanceOf[this.type] }
}

class NBCacheIF(val p: SpMVAccelWrapperParams) extends Bundle {
  // interface towards processing element:
  val read = new NBCacheReadPortIF(p)
  val write = new CacheWritePortIF(p)

  // interface towards main mem
  val mem = new GenericMemoryMasterPort(p.toMRP())

  val writeComplete = Bool(OUTPUT)

  val base = UInt(INPUT, 32)
  val startInit = Bool(INPUT)
  val startWrite = Bool(INPUT)
  val done = Bool(OUTPUT)

  // init indicator and cache stat outputs
  val readCount = UInt(OUTPUT, 32)
  val readMissCount = UInt(OUTPUT, 32)
  val writeCount = UInt(OUTPUT, 32)
  val writeMissCount = UInt(OUTPUT, 32)
  val conflictMissCount = UInt(OUTPUT, 32)
  val cacheState = UInt(OUTPUT, 32)

  override def clone = { new NBCacheIF(p).asInstanceOf[this.type] }
}

class NBTagResponse(indBits: Int, tagBits: Int, dataBits: Int) extends Bundle {
  val ind = UInt(width = indBits)
  val reqCMS = Bool()
  val reqTag = UInt(width = tagBits)
  val rspTag = UInt(width = tagBits)
  val rspValid = Bool()
  val rspData = UInt(width = dataBits)
  val opData = UInt(width = dataBits)

  override def clone = {
    new NBTagResponse(indBits, tagBits, dataBits).asInstanceOf[this.type]
  }
}
