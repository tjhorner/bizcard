const song = require('./song.json')
const notes = song.tracks[1].notes

const dedupedNotes = notes.filter((value, index, self) =>
  index === self.findIndex((t) => (
    t.time === value.time
  ))
)

const segmentLengths = [
  5, // 0
  9, // 1
  11, // 2
  5, // 3
  9, // 4
  7, // 5
  7, // 6
  12, // 7
  12, // 8
  12, // 9
  9, // 10
  6, // 11
  8, // 12
  10, // 13
  6, // 14
  9, // 15
  14, // 16
  24, // 17
  6, // 18
  7, // 19
  9, // 20
  6, // 21
  9, // 22
  10, // 23
  13, // 24
  14, // 25
  6, // 26
  6, // 27
  12, // 28
  7, // 29
  7, // 30
  9, // 31
  9, // 32
  10, // 33
  10, // 34
  9, // 35
  16, // 36
]

const segments = [ ]

for (const length of segmentLengths) {
  const segment = dedupedNotes.slice(0, length)
  segments.push(segment)
  dedupedNotes.splice(0, length)
}

segments.forEach((segment) => {
  segment.forEach((note, index) => {
    if (index !== segment.length - 1) {
      note.delayAfter = segment[index + 1].time - note.time
      note.pause = false
    } else {
      note.delayAfter = 0
      note.pause = true
    }
  })
})

const midiToFreq = (midi) => Math.round(440 * Math.pow(2, (midi - 69) / 12))

const flattenedSegments = segments.flat()

let generatedCode = "const NoteDefinition notes[] = {\n"

flattenedSegments.forEach((note, index) => {
  const freq = midiToFreq(note.midi)
  const duration = note.duration * 1000
  const delayAfter = note.delayAfter * 1000
  const pause = note.pause
  generatedCode += `  { ${freq}, ${duration}, ${delayAfter}, ${pause} },\n`
})

generatedCode += "};"

console.log(generatedCode)