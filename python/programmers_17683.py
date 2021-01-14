def solution(m, musicinfos):
    answer = None
    replacement = {
        "C#" : "H",
        "D#" : "I",
        "F#" : "J",
        "G#" : "K",
        "A#" : "L"
    }
    for k, v in replacement.items():
        m = m.replace(k,v)
    for music in musicinfos:
        s,e,title,sheet = music.split(",")
        for k, v in replacement.items():
            sheet = sheet.replace(k,v)
        sh,sm = map(int,s.split(":"))
        eh,em = map(int,e.split(":"))
        time= (eh*60+em) - (sh*60+sm) +1
        if time >= len(sheet):
            q, r = divmod(time,len(sheet))
            sheet = sheet * q + sheet[:r]
        else:
            sheet = sheet[:time]
        if m in sheet:
            if (not answer) or answer[1] < time:
                answer = [title, time]
    if not answer:
        return "(None)"
    return answer[0]