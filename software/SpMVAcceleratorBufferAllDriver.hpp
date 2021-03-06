#ifndef SpMVAcceleratorBufferAllDriver_H
#define SpMVAcceleratorBufferAllDriver_H
#include <assert.h>
class SpMVAcceleratorBufferAllDriver {
public:
 static unsigned int expSignature() {return 0x34182cf6;};
 SpMVAcceleratorBufferAllDriver(volatile unsigned int * baseAddr) {
  m_baseAddr = baseAddr; assert(signature() == expSignature());};
 // read+write register: startInit index: 12
 void startInit(unsigned int v) {m_baseAddr[12] = v;};
 unsigned int startInit() {return m_baseAddr[12];};
 // read+write register: startRegular index: 13
 void startRegular(unsigned int v) {m_baseAddr[13] = v;};
 unsigned int startRegular() {return m_baseAddr[13];};
 // read+write register: startWrite index: 14
 void startWrite(unsigned int v) {m_baseAddr[14] = v;};
 unsigned int startWrite() {return m_baseAddr[14];};
 // read+write register: numRows index: 15
 void numRows(unsigned int v) {m_baseAddr[15] = v;};
 unsigned int numRows() {return m_baseAddr[15];};
 // read+write register: numCols index: 16
 void numCols(unsigned int v) {m_baseAddr[16] = v;};
 unsigned int numCols() {return m_baseAddr[16];};
 // read+write register: numNZ index: 17
 void numNZ(unsigned int v) {m_baseAddr[17] = v;};
 unsigned int numNZ() {return m_baseAddr[17];};
 // read+write register: baseColPtr index: 18
 void baseColPtr(unsigned int v) {m_baseAddr[18] = v;};
 unsigned int baseColPtr() {return m_baseAddr[18];};
 // read+write register: baseRowInd index: 19
 void baseRowInd(unsigned int v) {m_baseAddr[19] = v;};
 unsigned int baseRowInd() {return m_baseAddr[19];};
 // read+write register: baseNZData index: 20
 void baseNZData(unsigned int v) {m_baseAddr[20] = v;};
 unsigned int baseNZData() {return m_baseAddr[20];};
 // read+write register: baseInputVec index: 21
 void baseInputVec(unsigned int v) {m_baseAddr[21] = v;};
 unsigned int baseInputVec() {return m_baseAddr[21];};
 // read+write register: baseOutputVec index: 22
 void baseOutputVec(unsigned int v) {m_baseAddr[22] = v;};
 unsigned int baseOutputVec() {return m_baseAddr[22];};
 // read+write register: thresColPtr index: 23
 void thresColPtr(unsigned int v) {m_baseAddr[23] = v;};
 unsigned int thresColPtr() {return m_baseAddr[23];};
 // read+write register: thresRowInd index: 24
 void thresRowInd(unsigned int v) {m_baseAddr[24] = v;};
 unsigned int thresRowInd() {return m_baseAddr[24];};
 // read+write register: thresNZData index: 25
 void thresNZData(unsigned int v) {m_baseAddr[25] = v;};
 unsigned int thresNZData() {return m_baseAddr[25];};
 // read+write register: thresInputVec index: 26
 void thresInputVec(unsigned int v) {m_baseAddr[26] = v;};
 unsigned int thresInputVec() {return m_baseAddr[26];};
 // read+write register: statBackend index: 1
 void statBackend(unsigned int v) {m_baseAddr[1] = v;};
 unsigned int statBackend() {return m_baseAddr[1];};
 // read+write register: statFrontend index: 2
 void statFrontend(unsigned int v) {m_baseAddr[2] = v;};
 unsigned int statFrontend() {return m_baseAddr[2];};
 // read+write register: hazardStalls index: 3
 void hazardStalls(unsigned int v) {m_baseAddr[3] = v;};
 unsigned int hazardStalls() {return m_baseAddr[3];};
 // read+write register: bwMon_totalCycles index: 4
 void bwMon_totalCycles(unsigned int v) {m_baseAddr[4] = v;};
 unsigned int bwMon_totalCycles() {return m_baseAddr[4];};
 // read+write register: bwMon_activeCycles index: 5
 void bwMon_activeCycles(unsigned int v) {m_baseAddr[5] = v;};
 unsigned int bwMon_activeCycles() {return m_baseAddr[5];};
 // read+write register: bwMon_noValidButReady index: 6
 void bwMon_noValidButReady(unsigned int v) {m_baseAddr[6] = v;};
 unsigned int bwMon_noValidButReady() {return m_baseAddr[6];};
 // read+write register: bwMon_noReadyButValid index: 7
 void bwMon_noReadyButValid(unsigned int v) {m_baseAddr[7] = v;};
 unsigned int bwMon_noReadyButValid() {return m_baseAddr[7];};
 // read+write register: ocmWords index: 8
 void ocmWords(unsigned int v) {m_baseAddr[8] = v;};
 unsigned int ocmWords() {return m_baseAddr[8];};
 // read+write register: fifoCountsCPRI index: 9
 void fifoCountsCPRI(unsigned int v) {m_baseAddr[9] = v;};
 unsigned int fifoCountsCPRI() {return m_baseAddr[9];};
 // read+write register: fifoCountsNZIV index: 10
 void fifoCountsNZIV(unsigned int v) {m_baseAddr[10] = v;};
 unsigned int fifoCountsNZIV() {return m_baseAddr[10];};
 // read+write register: debug index: 11
 void debug(unsigned int v) {m_baseAddr[11] = v;};
 unsigned int debug() {return m_baseAddr[11];};
 // read+write register: signature index: 0
 void signature(unsigned int v) {m_baseAddr[0] = v;};
 unsigned int signature() {return m_baseAddr[0];};

protected:
 volatile unsigned int * m_baseAddr;
};
#endif
